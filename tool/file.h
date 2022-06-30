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
        File();
        ~File();
        bool IsFile();
        uint8_t ReadAll(uint8_t *a_ucOutData);
        uint8_t Save(const char *a_cFileName, const uint8_t *a_ucInDdata, size_t a_sInSize);
        size_t Size();
    private:
        std::string m_sFilename;
    };
}


#endif //IMAGE_FILE_H
