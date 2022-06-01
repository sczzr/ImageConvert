//
// Created by Caste on 2022/5/18.
//

#include "Command.h"
#include <stdio.h>
#include <string.h>
#include <cstdlib>

Command::Command() {
    i_hAlignment = 0;
    i_vAlignment = 0;
    b_alphaPreMultiply = false;
    pstrSourceImage = nullptr;
    pstrOutputImage = nullptr;
}

bool Command::ProcessCommandLineArguments(int a_iArgs, const char *a_apstrArgs[]) {
    static const bool DEBUG_PRINT = false;
    if(a_iArgs <= 1)
    {
        printf("Error: missing arguments.\n");
        return true;
    }
    for (int iArg = 1; iArg < a_iArgs; ++iArg) {
        if(DEBUG_PRINT)
        {
            printf("%s: %u %s\n", a_apstrArgs[0], iArg,a_apstrArgs[iArg]);
        }

        if(strcmp(a_apstrArgs[iArg],"-alignHV") == 0)
        {
            ++iArg;
            if(iArg + 1 >= a_iArgs)
            {
                printf("Error: missing alignment argument for -alignHV.\n");
                return true;
            }
            else
            {
                i_hAlignment = atoi(a_apstrArgs[iArg]);
                ++iArg;
                i_vAlignment = atoi(a_apstrArgs[iArg]);
            }
        }
        else if(strcmp(a_apstrArgs[iArg],"-alphapremul") == 0)
        {
            b_alphaPreMultiply = true;
        }
        else if(strcmp(a_apstrArgs[iArg],"-coverage") == 0)
        {
            if (pstrSourceImage == nullptr) {
                printf("Error:missing source image.\n");
                return true;
            }
            pstrOutputImage = pstrSourceImage;
        }
        else if(strcmp(a_apstrArgs[iArg],"-output") == 0)
        {
            ++iArg;
            if(iArg >= a_iArgs)
            {
                printf("Error: missing decode argument for -output.\n");
                return true;
            }
            else
            {
                pstrOutputImage = new char[strlen(a_apstrArgs[iArg] + 1)];
                strcpy(pstrOutputImage,a_apstrArgs[iArg]);
            }
        }
        else if(strcmp(a_apstrArgs[iArg],"-path") == 0)
        {
            ++iArg;
            if(iArg >= a_iArgs)
            {
                printf("Error: missing decode argument for -output.\n");
                return true;
            }
            else
            {
                pstrOutputImage = new char[strlen(a_apstrArgs[iArg] + 1)];
                strcpy(pstrOutputImage,a_apstrArgs[iArg]);
            }
        }
        else
        {
            if (pstrSourceImage != nullptr) {
                printf("Error:only support one source image(%s).\n", a_apstrArgs[iArg]);
                return true;
            }
            pstrSourceImage = new char[strlen(a_apstrArgs[iArg] + 1)];
            strcpy(pstrSourceImage, a_apstrArgs[iArg]);
        }
    }

    if(pstrSourceImage == nullptr)
    {
        printf("Error: missing source image.\n");
    }

    if(pstrOutputImage == nullptr)
    {
        printf("Error: missing -output encode image.\n");
    }
    return false;
}


