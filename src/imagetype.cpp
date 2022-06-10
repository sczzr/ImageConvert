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
