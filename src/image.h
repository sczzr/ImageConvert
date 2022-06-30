//
// Created by Caste on 2022/5/27.
//

#ifndef PNGTOOL_IMAGETYPE_H
#define PNGTOOL_IMAGETYPE_H

#include "../tool/color.h"
#include "imagetype.h"
#include "stdint.h"

namespace General {
    class Resource;

    class Color;
}
namespace ImageTool {

    class Codec;

    class Image : public ImageType {
    public:
        struct Data {
            Format format;
            unsigned stride;
            unsigned width;
            unsigned height;
            unsigned char *pixels;
            Data()
            {
                format = ImageType::Format::None;
                stride = 0;
                width = 0;
                height = 0;
                pixels = nullptr;
            }
            Data(unsigned a_uiWidth, unsigned a_uiHeight,Format a_format,void* a_ptrPixels)
                :width(a_uiWidth),height(a_uiHeight),format(a_format),m_autoAlloc()
            {
                uint8_t depthByte = GetDepthByte(a_format);
                stride = width * depthByte;
                if (a_ptrPixels == nullptr)
                {
                    m_autoAlloc = true;
                    pixels = new uint8_t[a_uiWidth*a_uiHeight*depthByte]();
                }
            }
            ~Data()
            {
                if (m_autoAlloc && pixels!= nullptr)
                {
                    delete[] pixels;
                }
            }
        private:
            bool m_autoAlloc;
        };
        Image(const char *a_pstrFileName);

        explicit Image(General::Resource &a_Resource);

        ~Image();

        int
        Read(int a_iPixelX = -1, int a_iPixelY = -1);

        int
        ReadRaw(Filetype a_eType, int a_iPixelX = -1, int a_iPixelY = -1);

        int
        Save(const char *a_pstrFilename, Filetype a_efileType = ImageType::Filetype::PNG);

        int
        Save(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiWidth, unsigned int a_uiHeight,
             Format a_Format, uint8_t a_ucBitDepth);

        int
        SaveAlign(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiHAlignCoef,
                  unsigned int a_uiVAlignCoef, const General::Color &a_rCFillColor = General::Color());

        int
        SavePreMulAlphaWithAlign(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiHAlignCoef,
                                 unsigned int a_uiVAlignCoef,
                                 const General::Color &a_rCFillColor = General::Color());

        void
        Show();

    private:
        void
        ImageCopy(Data &a_dstImage, Data &a_srcImage);

    private:
        Data m_data;
        ImageType m_type;
        General::Resource *m_resource;
        Codec *m_codec;
    };

} // ImageTool

#endif //PNGTOOL_IMAGETYPE_H
