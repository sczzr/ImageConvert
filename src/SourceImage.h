//
// Created by Caste on 2022/5/13.
//

#ifndef PNGTOOL_SOURCEIMAGE_H
#define PNGTOOL_SOURCEIMAGE_H

#include "ImageType.h"

namespace ImageTool {
    class SourceImage : public ImageType {
    public:


        SourceImage(const char *a_pstrFilename, Filetype a_eFiletype);

        ~SourceImage();

        unsigned int Width() const { return m_uiWidth; }

        unsigned int Height() const { return m_uiHeight; }

        unsigned char *Pixels() const { return m_ptr; }

        void save(const char *name);

        void save(const char *name, unsigned int width, unsigned int height);

    private:
        void decode(Filetype type);

        void encode(const char *name);

    private:
        unsigned int m_uiWidth;
        unsigned int m_uiHeight;
        unsigned char *m_ptr;
        const char *m_filename;
    };
}


#endif //PNGTOOL_SOURCEIMAGE_H
