//
// Created by Shawn on 6/7/2022.
//

#ifndef IMAGE_FILE_H
#define IMAGE_FILE_H

#include "string"

namespace General{
    class File {
    public:
        File(const char* a_pstrFilename);
        ~File();
        bool isFile();
    private:
        std::string m_sFilename;
    };
}


#endif //IMAGE_FILE_H
