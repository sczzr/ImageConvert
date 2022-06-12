//
// Created by Caste on 2022/5/13.
//

#ifndef PNGTOOL_SOURCEIMAGE_H
#define PNGTOOL_SOURCEIMAGE_H

#include "imagetype.h"

namespace ImageTool {
    class SourceImage : public ImageType {
    public:

        SourceImage();

        SourceImage(const char *a_pstrFileName, Filetype a_eFiletype);

        ~SourceImage();

        unsigned int Width() const { return m_uiWidth; }

        unsigned int Height() const { return m_uiHeight; }

        unsigned char *Pixels() const { return m_ptrSourcePixels; }

        void Decode(const char *a_pstrFileName, Filetype a_eFiletype);

        void Encode(const char *a_pstrFileName, Filetype a_eFiletype, unsigned int a_uiWidth , unsigned int a_uiHeight);

        void Encode(const char *a_pstrFileName, Filetype a_eFiletype, unsigned int a_uiWidth, unsigned int a_uiHeight,
                    unsigned char *a_ptrPixels);

    private:
        unsigned loadppm_decode_file(unsigned char** out, unsigned* w, unsigned* h, const char* filename,
                                     unsigned bitdepth);
        unsigned loadppm_encode_file(const char* filename, const unsigned char* image, unsigned w, unsigned h);
    private:
        unsigned int m_uiWidth;
        unsigned int m_uiHeight;
        unsigned char *m_ptrSourcePixels;
        const char *m_pstrFilename;
    };
}


#endif //PNGTOOL_SOURCEIMAGE_H
