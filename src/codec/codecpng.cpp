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
                          const unsigned char *a_ptrInData, unsigned a_uiInSize) {
        lodepng_decode_memory(a_ptrOutputData, a_uiWidth, a_uiHeight, a_ptrInData, a_uiInSize, LCT_RGB, 8);
    }

    void CodecPng::Encode(unsigned char **a_ptrOutputData, unsigned a_uiOutSize, unsigned a_uiHeight,
                          const unsigned char *a_ptrInData, unsigned a_uiWidth) {
        lodepng_encode_memory(a_ptrOutputData, reinterpret_cast<size_t *>(a_uiOutSize), a_ptrInData, a_uiWidth,
                              a_uiHeight, LCT_RGB, 8);
    }

} // ImageTool