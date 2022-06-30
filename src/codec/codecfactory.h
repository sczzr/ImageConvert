//
// Created by shawn on 2022/6/23.
//

#ifndef IMAGE_CODECFACTORY_H
#define IMAGE_CODECFACTORY_H

#include "imagetype.h"
#include "codec.h"
namespace ImageTool{
    class CodecFactory
    {
    public:
        Codec * CodecCreater(ImageType::Filetype a_fileType);
    };
}

#endif //IMAGE_CODECFACTORY_H
