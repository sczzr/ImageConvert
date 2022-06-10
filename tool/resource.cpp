//
// Created by Caste on 2022/6/1.
//

#include "resource.h"
#include "file.h"


namespace General {
    Resource::Resource(const char *a_pstrResourcePath) :
            m_sResourcePath(a_pstrResourcePath) {
        std::size_t found = m_sResourcePath.find_last_of("/\\");
        if (File(a_pstrResourcePath).isFile()) {
            m_sDirectoryPath = m_sResourcePath.substr(0, found);
            m_sFilePath = m_sResourcePath;
            m_sFilename = m_sResourcePath.substr(found + 1);
            std::size_t found = m_sResourcePath.find_last_of("/\\");
            m_sFiletype = m_sResourcePath.substr(m_sResourcePath.find_last_of(".") + 1, m_sResourcePath.size());


        } else {
            m_sDirectoryPath = m_sResourcePath;
            m_sFilePath = "";
            m_sFilename = "";
            m_sFiletype = "";
        }
    }

    const char *Resource::FileName() const {
        return m_sFilename.c_str();
    }

    const char *Resource::DirectoryPath() const {
        return m_sDirectoryPath.c_str();
    }

    const char *Resource::FileType() const {
        return m_sFiletype.c_str();
    }

    const char *Resource::FilePath() const {
        return m_sFilePath.c_str();
    }


} // General