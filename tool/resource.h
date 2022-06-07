//
// Created by Caste on 2022/6/1.
//

#ifndef IMAGE_RESOURCE_H
#define IMAGE_RESOURCE_H
#include "string"

namespace General {

    class Resource {
    public:
        explicit Resource(const char* a_pstrResourcePath);
        const char * GetPath() const;
        const char * GetFileName() const;
    private:
        std::string m_sResourcePath;
        std::string m_sPath;
        std::string m_sFilename;
    };

} // General

#endif //IMAGE_RESOURCE_H
