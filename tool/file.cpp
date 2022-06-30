//
// Created by Shawn on 6/7/2022.
//

#include "file.h"
#include "fstream"

General::File::File(const char *a_pstrFilename) :
        m_sFilename(a_pstrFilename) {

}

General::File::~File() {

}

bool General::File::IsFile() {
    return true;
}

uint8_t General::File::ReadAll(uint8_t *a_ucOutData) {
    std::ifstream file(m_sFilename.c_str(), std::ios::in | std::ios::binary);
    if (!file)
    {
        printf("ERROR: File open failed '%s'\n",m_sFilename.c_str());
        return 1;
    }
    file.read(reinterpret_cast<char *>(a_ucOutData), Size());
    if (!file)
    {
        printf("ERROR: File open failed '%s'\n",m_sFilename.c_str());
        return 1;
    }
    return 0;
}

size_t General::File::Size() {
    std::ifstream file(m_sFilename.c_str(), std::ios::in | std::ios::binary);
    int size = 0;
    if(file.is_open())
    {
        file.seekg(0,std::ios::end);
        size = file.tellg();
        file.seekg(0,std::ios::beg);
    }
    return size;
}

uint8_t General::File::Save(const char *a_cFileName, const uint8_t *a_ucInDdata, size_t a_sInSize) {
    std::ofstream file(a_cFileName,std::ios::out|std::ios::binary);
    if (!file)
    {
        printf("ERROR: File open failed '%s'\n", a_cFileName);
        return 1;
    }
    file.write(reinterpret_cast<const char *>(a_ucInDdata), a_sInSize);
}

General::File::File() {

}
