//
// Created by Caste on 2022/5/13.
//
#include <iostream>
#include <stdio.h>
#include "Command.h"
#include "SourceImage.h"
using namespace ImageTool;

int main(int argc, const char* argv[])
{
    Command command;
    if (command.ProcessCommandLineArguments(argc,argv))
    {
        exit(1);
    }
    SourceImage png(command.sourceImage());
    png.save(command.pstrOutputImage);
}