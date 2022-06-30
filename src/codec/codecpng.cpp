//
// Created by Shawn on 6/17/2022.
//

#include "codecpng.h"
#include "lodepng.h"

namespace ImageTool {
    ImageType::Filetype CodecPng::type() const {
        return ImageType::Filetype::PNG;
    }

    void CodecPng::Decode(unsigned char **a_ptrOutputData, unsigned *a_uiWidth, unsigned *a_uiHeight,
                          const unsigned char *a_ptrInData,
                          unsigned a_uiInSize, ImageType::Format a_pixFormat, uint8_t ucBitDepth) {
        lodepng_decode_memory(a_ptrOutputData, a_uiWidth, a_uiHeight, a_ptrInData, a_uiInSize, LCT_RGBA, ucBitDepth);
    }

    void
    CodecPng::Encode(unsigned char **a_ptrOutputData, unsigned *a_uiOutSize, unsigned a_uiWidth, unsigned a_uiHeight,
                     const unsigned char *a_ptrInData, ImageType::Format a_pixFormat, uint8_t a_ucBitDepth) {
        lodepng_encode_memory(a_ptrOutputData, a_uiOutSize, a_ptrInData, a_uiWidth,
                              a_uiHeight, LCT_RGBA, a_ucBitDepth);
    }

} // ImageTool