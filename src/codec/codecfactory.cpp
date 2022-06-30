//
// Created by shawn on 2022/6/23.
//
#include "codecfactory.h"
#include "codecpng.h"

using namespace ImageTool;

Codec *ImageTool::CodecFactory::CodecCreater(ImageType::Filetype a_fileType) {
    switch (a_fileType) {
        case ImageType::Filetype::PNG:
            return new CodecPng();
        default:
            return nullptr;
    }
}
