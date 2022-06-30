//
// Created by Shawn on 6/17/2022.
//

#ifndef IMAGE_CODEC_H
#define IMAGE_CODEC_H

#include "imagetype.h"

namespace ImageTool {

    class Codec {
    public:
        virtual ImageType::Filetype type() const = 0;

        virtual void Decode(unsigned char **a_ptrOutputData, unsigned *a_uiWidth, unsigned *a_uiHeight,
                            const unsigned char *a_ptrInData,
                            unsigned a_uiInSize, ImageType::Format a_pixFormat, uint8_t ucBitDepth) = 0;

        virtual void
        Encode(unsigned char **a_ptrOutputData, unsigned *a_uiOutSize, unsigned a_uiWidth, unsigned a_uiHeight,
               const unsigned char *a_ptrInData, ImageType::Format a_pixFormat, uint8_t a_ucBitDepth) = 0;

    };


} // ImageTool

#endif //IMAGE_CODEC_H
