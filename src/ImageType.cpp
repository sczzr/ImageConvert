//
// Created by Caste on 2022/5/27.
//

#include "ImageType.h"
#include "SourceImage.h"

namespace ImageTool {

    Image::Image(const char *a_pstrFilename) {

        SourceImage(a_pstrFilename)
    }

    Image::~Image() {

    }

    int Image::Read(int a_iPixelX, int a_iPixelY) {
        return 0;
    }

    int Image::ReadRaw(ImageType::Filetype a_eType, int a_iPixelX, int a_iPixelY) {
        return 0;
    }

    int Image::Save(const char *a_pstrFilename, ImageType::Filetype a_efileType) {
        return 0;
    }

    int Image::Save(const char *a_pstrFilename, unsigned int a_uiWidth, unsigned int a_uiHeight,
                    ImageType::Filetype a_efileType) {
        return 0;
    }

    int Image::SaveAlign(const char *a_pstrFilename, unsigned int a_uiAlignX, unsigned int a_uiAlignY,
                         ImageType::Filetype a_efileType, const General::Color &a_rCFillColor) {
        return 0;
    }
} // ImageTool