//
// Created by Shawn on 6/2/2022.
//

#include "iostream"
#include "resource.h"
#include "image.h"

int main(int argc, const char* argv[])
{
    General::Resource res("E:\\Picture\\Demo\\png\\Pngtreeblue geometric shape with dot_3719431.png");
    std::cout << res.DirectoryPath() << std::endl;
    std::cout << res.FileName() << std::endl;
    std::cout << res.FileType() << std::endl;
    ImageTool::Image image(res);
    image.Read();
    image.Save("E:\\Picture\\Demo\\png\\Pngtreeblue.png", ImageTool::ImageType::Filetype::PNG, 1000, 1000,
               ImageTool::ImageType::Format::BGRA8888, 0);
}