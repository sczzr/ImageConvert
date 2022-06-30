//
// Created by Shawn on 6/10/2022.
//

#ifndef IMAGE_IMAGETYPE_H
#define IMAGE_IMAGETYPE_H

#include "stdint.h"

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

        Filetype GetType(const char *type);
        uint8_t GetDepth(Format a_format);
        static uint8_t GetDepthByte(Format a_format);

    };
} // ImageTool

#endif //IMAGE_IMAGETYPE_H
