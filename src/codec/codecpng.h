//
// Created by Shawn on 6/17/2022.
//

#ifndef IMAGE_CODEC_PNG_H
#define IMAGE_CODEC_PNG_H

#include "codec.h"

namespace ImageTool {

    class CodecPng : public Codec {
        virtual ImageType::Filetype type() const override;

        virtual void
        Decode(unsigned char **a_ptrOutputData, unsigned *a_uiWidth, unsigned *a_uiHeight,
               const unsigned char *a_ptrInData, unsigned a_uiInSize, ImageType::Format a_pixFormat,
               uint8_t ucBitDepth) override;

        virtual void
        Encode(unsigned char **a_ptrOutputData, unsigned *a_uiOutSize, unsigned a_uiWidth, unsigned a_uiHeight,
               const unsigned char *a_ptrInData, ImageType::Format a_pixFormat, uint8_t a_ucBitDepth) override;
    };

} // ImageTool

#endif //IMAGE_CODEC_PNG_H
