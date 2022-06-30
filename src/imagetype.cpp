//
// Created by Shawn on 6/10/2022.
//

#include "imagetype.h"
#include <string>

using  namespace ImageTool;

ImageType::Filetype ImageType::GetType(const char *type) {
    if (_stricmp("png", type) == 0) {
        return ImageTool::ImageType::Filetype::PNG;
    } else if (_stricmp("jpg", type) == 0) {
        return ImageTool::ImageType::Filetype::JPG;
    } else if (_stricmp("ppm", type) == 0) {
        return ImageTool::ImageType::Filetype::PPM;
    } else {
        return ImageTool::ImageType::Filetype::None;
    }
}

uint8_t ImageType::GetDepth(ImageType::Format a_format) {
    switch (a_format) {
        case Format::RGB565:
            return 16;
        case Format::BGR565:
            return 16;
        case Format::RGB888:
            return 24;
        case Format::RGBA8888:
            return 32;
        case Format::BGRA8888:
            return 32;
        default:
            return 0;
    }
}

uint8_t ImageType::GetDepthByte(ImageType::Format a_format) {
    switch (a_format) {
        case Format::RGB565:
            return 2;
        case Format::BGR565:
            return 2;
        case Format::RGB888:
            return 3;
        case Format::RGBA8888:
            return 4;
        case Format::BGRA8888:
            return 4;
        default:
            return 0;
    }
}