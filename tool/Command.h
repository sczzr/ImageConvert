//
// Created by Caste on 2022/5/18.
//

#ifndef PNGTOOL_COMMAND_H
#define PNGTOOL_COMMAND_H


class Command {
public:
    Command();
    bool ProcessCommandLineArguments(int a_iArgs, const char *a_apstrArgs[]);
    const char *sourceImage() const{return pstrSourceImage;}
    int i_hAlignment;
    int i_vAlignment;
    bool b_alphaPreMultiply;
    char *pstrSourceImage;
    char *pstrOutputImage;
};


#endif //PNGTOOL_COMMAND_H
