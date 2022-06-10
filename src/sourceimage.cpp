//
// Created by Caste on 2022/5/13.
//
#include "sourceimage.h"
#include "lodepng.h"

using namespace ImageTool;


SourceImage::SourceImage():
    m_pstrFilename(),
    m_uiWidth(),
    m_uiHeight(),
    m_ptrSourcePixels() {

}

SourceImage::SourceImage(const char *a_pstrFilename, Filetype a_eFiletype) :
        m_pstrFilename(a_pstrFilename),
        m_uiWidth(),
        m_uiHeight(),
        m_ptrSourcePixels() {
    Decode(nullptr, a_eFiletype);
}


SourceImage::~SourceImage() {
    if (m_ptrSourcePixels != nullptr) {
        free(m_ptrSourcePixels);
    }
}

void SourceImage::Decode(const char *a_pstrFileName, Filetype a_eFiletype) {
    if (m_ptrSourcePixels == nullptr) {
        switch (a_eFiletype) {
            case Filetype::PNG:
                lodepng_decode_file(&m_ptrSourcePixels, &m_uiWidth, &m_uiHeight, m_pstrFilename, LCT_RGBA, 8);
                break;
            default:
                break;
        }
    }
}

void SourceImage::save(const char *a_pstrOutName) {
    int width = m_uiWidth;
    int height = m_uiHeight;
    int channel = 4;
    width = (m_uiWidth + 16 - 1) / 16 * 16;
    height = (m_uiHeight + 4 - 1) / 4 * 4;
    int stride = width * channel;
    int size = width * height * channel;
    uint8_t *new_ptr = (uint8_t *) malloc(size);
    memset(new_ptr, 0, size);
    for (int i = 0; i < height; ++i) {
        if (i < m_uiHeight) {
            for (int j = 0; j < stride; j += channel) {
                if (j < m_uiWidth * channel) {
                    uint32_t r = m_ptrSourcePixels[i * m_uiWidth * channel + j];
                    uint32_t g = m_ptrSourcePixels[i * m_uiWidth * channel + j + 1];
                    uint32_t b = m_ptrSourcePixels[i * m_uiWidth * channel + j + 2];
                    uint32_t a = m_ptrSourcePixels[i * m_uiWidth * channel + j + 3];
                    new_ptr[i * stride + j] = r * a >> 8;
                    new_ptr[i * stride + j + 1] = g * a >> 8;
                    new_ptr[i * stride + j + 2] = b * a >> 8;
                    new_ptr[i * stride + j + 3] = a;
                }
            }
        }
    }
    lodepng_encode32_file(a_pstrOutName, new_ptr, width, height);
    free(new_ptr);
}

void SourceImage::save(const char *a_pstrOutName, uint32_t a_uiWidth, uint32_t a_uiHeight) {
    int channel = 4;
    int stride = a_uiWidth * channel;
    uint8_t *new_ptr = (uint8_t *) malloc(a_uiWidth * m_uiHeight * channel);
    for (int i = 0; i < a_uiHeight; ++i) {
        for (int j = 0; j < stride; j += channel) {
            uint32_t r = m_ptrSourcePixels[i * m_uiWidth * channel + j];
            uint32_t g = m_ptrSourcePixels[i * m_uiWidth * channel + j + 1];
            uint32_t b = m_ptrSourcePixels[i * m_uiWidth * channel + j + 2];
            uint32_t a = m_ptrSourcePixels[i * m_uiWidth * channel + j + 3];
            new_ptr[i * stride + j] = r * a >> 8;
            new_ptr[i * stride + j + 1] = g * a >> 8;
            new_ptr[i * stride + j + 2] = b * a >> 8;
            new_ptr[i * stride + j + 3] = a;
        }
    }
    lodepng_encode32_file(a_pstrOutName, new_ptr, a_uiWidth, m_uiHeight);
    free(new_ptr);
}

void SourceImage::Encode(const char *a_pstrFileName, Filetype a_eFiletype, unsigned int a_uiWidth,
                         unsigned int a_uiHeight) {
    switch (a_eFiletype) {
        case Filetype::PNG:
            lodepng_encode32_file(a_pstrFileName, m_ptrSourcePixels, a_uiWidth, a_uiHeight);
            break;
        default:
            break;
    }
}

void SourceImage::Encode(const char *a_pstrFileName, Filetype a_eFiletype, unsigned int a_uiWidth,
                         unsigned int a_uiHeight, unsigned char *a_ptrPixels) {
    switch (a_eFiletype) {
        case Filetype::PNG:
            lodepng_encode32_file(a_pstrFileName, a_ptrPixels, a_uiWidth, a_uiHeight);
            break;
        default:
            break;
    }
}


