//
// Created by Caste on 2022/6/1.
//

#include "Resource.h"

namespace General {
    Resource::Resource(const char *a_pstrResourcePath) :
            m_ResourcePath(a_pstrResourcePath){
        std::size_t found = m_ResourcePath.find_last_of("/\\");
        m_Path = m_ResourcePath.substr(0,found);
        m_Filename = m_ResourcePath.substr(found+1);
    }

    const char *Resource::GetFileName() const {
        return m_Filename.c_str();
    }

    const char *Resource::GetPath() const {
        return m_Path.c_str();
    }


} // General