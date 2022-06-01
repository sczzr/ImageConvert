//
// Created by Caste on 2022/5/27.
//

#ifndef PNGTOOL_IMAGETYPE_H
#define PNGTOOL_IMAGETYPE_H

#include "../tool/Color.h"

namespace ImageTool {
    class ImageType {
    public:
        enum class Filetype {
            None = 0,
            PNG,
            JPG,
            PPM
        };

        enum class Format {
            None = 0,
            RGB565,
            BGR565,
            RGB888,
            BGR888,
            RGBA8888,
            BGRA8888
        };
    };

    class Image : public ImageType {
    public:
        Image(const char *a_pstrFilename);

        ~Image();

        int Read(int a_iPixelX = -1, int a_iPixelY = -1);

        int ReadRaw(Filetype a_eType, int a_iPixelX = -1, int a_iPixelY = -1);

        int Save(const char *a_pstrFilename, Filetype a_efileType = ImageType::Filetype::PNG);

        int Save(const char *a_pstrFilename, unsigned int a_uiWidth, unsigned int a_uiHeight,
                 Filetype a_efileType = ImageType::Filetype::PNG);

        int SaveAlign(const char *a_pstrFilename, unsigned int a_uiAlignX, unsigned int a_uiAlignY,
                      Filetype a_efileType = ImageType::Filetype::PNG, const General::Color &a_rCFillColor = General::Color());

    };

} // ImageTool

#endif //PNGTOOL_IMAGETYPE_H
