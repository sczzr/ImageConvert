//
// Created by Caste on 2022/5/27.
//

#include "image.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "resource.h"
#include "codec/codecfactory.h"
#include "file.h"

namespace ImageTool {
    Image::Image(const char *a_pstrFileName) {
        m_resource = new General::Resource(a_pstrFileName);
    }

    Image::~Image() {
        if (m_codec) {
            delete m_codec;
        }
    }

    int
    Image::Read(int a_iPixelX, int a_iPixelY) {
        CodecFactory factory;
        m_codec = factory.CodecCreater(GetType(m_resource->FileType()));
        General::File fd(m_resource->FilePath());

        size_t dataSize = fd.Size();
        uint8_t *rowData = new uint8_t[dataSize];
        fd.ReadAll(rowData);

        uint8_t *temp = nullptr;
        uint32_t width, height;
        Format format = Format::BGRA8888;
        m_codec->Decode(&temp, &width, &height, rowData, dataSize, format, 8);
        delete[] rowData;

        uint8_t *pixels = nullptr;
        uint8_t depthByte = GetDepthByte(format);
        if (a_iPixelX <= -1 && a_iPixelY <= -1) {
            int stride = width * depthByte;
            dataSize = stride * height;
            pixels = new uint8_t[dataSize];
            memcpy(pixels, temp, dataSize);
        } else {
            int stride = a_iPixelX * depthByte;
            dataSize = stride * a_iPixelY;
            pixels = new uint8_t[dataSize];
            for (int i = 0; i < a_iPixelY; ++i) {
                memcpy(&pixels[stride * i], &temp[width * depthByte * i], stride);
            }
            width = a_iPixelX;
            height = a_iPixelY;
        }
        m_data.pixels = pixels;
        m_data.width = width;
        m_data.height = height;
        m_data.stride = width * depthByte;
        m_data.format = format;
        free(temp);
        return 0;
    }

    int
    Image::ReadRaw(ImageType::Filetype a_eType, int a_iPixelX, int a_iPixelY) {
        return 0;
    }

    int
    Image::Save(const char *a_pstrFilename, ImageType::Filetype a_efileType) {
        return 0;
    }

    int
    Image::Save(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiWidth, unsigned int a_uiHeight,
                Format a_Format, uint8_t a_ucBitDepth) {
        uint8_t depthByte = GetDepthByte(a_Format);
        uint32_t dataSize = a_uiWidth * depthByte * a_uiHeight;
        Data out(a_uiWidth, a_uiHeight, a_Format, nullptr);
        ImageCopy(out, m_data);
        unsigned char *pixels = nullptr;
        unsigned pixelsSize;
        m_codec->Encode(&pixels, &pixelsSize, a_uiWidth, a_uiHeight, out.pixels, Format::BGRA8888, 8);
        General::File fd;
        fd.Save(a_pstrFilename, pixels, pixelsSize);
        free(pixels);
        return 0;
    }

    int
    Image::SaveAlign(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiHAlignCoef,
                     unsigned int a_uiVAlignCoef,
                     const General::Color &a_rCFillColor) {
        unsigned char *pixels = nullptr;
        unsigned pixelsSize;
        int sourceWidth = m_data.width;
        int sourceHeight = m_data.height;
        unsigned char *sourcePixels = m_data.pixels;
        int width = (sourceWidth + a_uiHAlignCoef - 1) / a_uiHAlignCoef * a_uiHAlignCoef;
        int height = (sourceHeight + a_uiVAlignCoef - 1) / a_uiVAlignCoef * a_uiVAlignCoef;

        int channel = 4;
        int stride = width * channel;
        int size = width * height * channel;
        uint8_t *new_ptr = (uint8_t *) malloc(size);
        memset(new_ptr, 0, size);
        for (int i = 0; i < height; ++i) {
            if (i < sourceHeight) {
                for (int j = 0; j < stride; j += channel) {
                    if (j < sourceWidth * channel) {
                        uint32_t r = sourcePixels[i * sourceWidth * channel + j];
                        uint32_t g = sourcePixels[i * sourceWidth * channel + j + 1];
                        uint32_t b = sourcePixels[i * sourceWidth * channel + j + 2];
                        uint32_t a = sourcePixels[i * sourceWidth * channel + j + 3];
                        new_ptr[i * stride + j] = r;
                        new_ptr[i * stride + j + 1] = g;
                        new_ptr[i * stride + j + 2] = b;
                        new_ptr[i * stride + j + 3] = a;
                    }
                }
            }
        }
        m_codec->Encode(&pixels, &pixelsSize, width, height, new_ptr, Format::BGRA8888, 0);
        free(pixels);
        free(new_ptr);
        return 1;
    }

    int
    Image::SavePreMulAlphaWithAlign(const char *a_pstrFilename, ImageType::Filetype a_efileType,
                                    unsigned int a_uiHAlignCoef, unsigned int a_uiVAlignCoef,
                                    const General::Color &a_rCFillColor) {
        unsigned char *pixels = nullptr;
        unsigned pixelsSize;
        int sourceWidth = m_data.width;
        int sourceHeight = m_data.height;
        unsigned char *sourcePixels = m_data.pixels;
        int width = (sourceWidth + a_uiHAlignCoef - 1) / a_uiHAlignCoef * a_uiHAlignCoef;
        int height = (sourceHeight + a_uiVAlignCoef - 1) / a_uiVAlignCoef * a_uiVAlignCoef;

        int channel = 4;
        int stride = width * channel;
        int size = width * height * channel;
        uint8_t *new_ptr = (uint8_t *) malloc(size);
        memset(new_ptr, 0, size);
        memcpy(new_ptr, sourcePixels, sourceHeight * sourceWidth);
        for (int i = 0; i < height; ++i) {
            if (i < sourceHeight) {
                for (int j = 0; j < stride; j += channel) {
                    if (j < sourceWidth * channel) {
                        uint32_t r = sourcePixels[i * sourceWidth * channel + j];
                        uint32_t g = sourcePixels[i * sourceWidth * channel + j + 1];
                        uint32_t b = sourcePixels[i * sourceWidth * channel + j + 2];
                        uint32_t a = sourcePixels[i * sourceWidth * channel + j + 3];
                        new_ptr[i * stride + j] = r * a >> 8;
                        new_ptr[i * stride + j + 1] = g * a >> 8;
                        new_ptr[i * stride + j + 2] = b * a >> 8;
                        new_ptr[i * stride + j + 3] = a;
                    }
                }
            }
        }
        m_codec->Encode(&pixels, &pixelsSize, width, height, new_ptr, Format::BGRA8888, 0);
        free(new_ptr);
        free(pixels);
        return 1;
    }

    Image::Image(General::Resource &a_Resource) {
        m_resource = new General::Resource(a_Resource);
    }

    void
    Image::Show() {
        printf("Todo\n");
    }

    void
    Image::ImageCopy(Data &a_dstImage, Data &a_srcImage) {
        assert(a_srcImage.pixels);
        assert(a_dstImage.pixels);
        assert(a_srcImage.format == a_dstImage.format);
        uint8_t depthByte = GetDepthByte(a_srcImage.format);

        for (int i = 0; i < a_dstImage.height; ++i) {
            for (int j = 0; j < a_dstImage.width * depthByte; ++j) {
                if (a_srcImage.width * depthByte > j && a_srcImage.height > i) {
                    a_dstImage.pixels[i * a_dstImage.width * depthByte + j] = a_srcImage.pixels[
                            i * a_srcImage.width * depthByte + j];
                } else {
                    a_dstImage.pixels[i * a_dstImage.width * depthByte + j] = 0;
                }
            }
        }
    }
} // ImageTool