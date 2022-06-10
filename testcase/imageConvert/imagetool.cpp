//
// Created by Caste on 2022/5/13.
//
#include <iostream>
#include <stdio.h>
#include "command.h"
#include "sourceimage.h"
#include "resource.h"
#include "image.h"

using namespace ImageTool;


int main(int argc, const char *argv[]) {
    Command command;
    if (command.ProcessCommandLineArguments(argc, argv)) {
        exit(1);
    }
    Image image(command.sourceImage());
    image.SavePreMulAlphaWithAlign(command.sourceImage(), ImageTool::ImageType::Filetype::PNG, 16, 4);
}