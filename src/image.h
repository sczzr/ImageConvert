//
// Created by Caste on 2022/5/27.
//

#ifndef PNGTOOL_IMAGETYPE_H
#define PNGTOOL_IMAGETYPE_H

#include "../tool/color.h"
#include "sourceimage.h"

namespace ImageTool {

    class Image : public ImageType {
    public:
        Image(const char *a_pstrFilename);

        ~Image();

        int Read(int a_iPixelX = -1, int a_iPixelY = -1);

        int ReadRaw(Filetype a_eType, int a_iPixelX = -1, int a_iPixelY = -1);

        int Save(const char *a_pstrFilename, Filetype a_efileType = ImageType::Filetype::PNG);

        int Save(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiWidth,
                 unsigned int a_uiHeight);

        int SaveAlign(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiHAlignCoef,
                      unsigned int a_uiVAlignCoef, const General::Color &a_rCFillColor = General::Color());


        int SavePreMulAlphaWithAlign(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiHAlignCoef,
                                     unsigned int a_uiVAlignCoef, const General::Color &a_rCFillColor = General::Color());

    private:
        SourceImage m_SourceImage;
    };

} // ImageTool

#endif //PNGTOOL_IMAGETYPE_H
