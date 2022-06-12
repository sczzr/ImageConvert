//
// Created by Caste on 2022/5/13.
//
#include "sourceimage.h"
#include "lodepng.h"

using namespace ImageTool;


SourceImage::SourceImage():
    m_pstrFilename(),
    m_uiWidth(),
    m_uiHeight(),
    m_ptrSourcePixels() {

}

SourceImage::SourceImage(const char *a_pstrFileName, Filetype a_eFiletype) :
        m_pstrFilename(a_pstrFileName),
        m_uiWidth(),
        m_uiHeight(),
        m_ptrSourcePixels() {
    Decode(a_pstrFileName, a_eFiletype);
}


SourceImage::~SourceImage() {
    if (m_ptrSourcePixels != nullptr) {
        free(m_ptrSourcePixels);
    }
}

void SourceImage::Decode(const char *a_pstrFileName, Filetype a_eFiletype) {
    if (m_ptrSourcePixels == nullptr) {
        unsigned err = 0;
        switch (a_eFiletype) {
            case Filetype::PNG:
                err = lodepng_decode_file(&m_ptrSourcePixels, &m_uiWidth, &m_uiHeight, a_pstrFileName, LCT_RGBA, 8);
                break;
            default:
                break;
        }
        if (err)
        {
            printf("load picture failed .\n");
        }
    }
}

void SourceImage::Encode(const char *a_pstrFileName, Filetype a_eFiletype, unsigned int a_uiWidth,
                         unsigned int a_uiHeight) {
    switch (a_eFiletype) {
        case Filetype::PNG:
            lodepng_encode32_file(a_pstrFileName, m_ptrSourcePixels, a_uiWidth, a_uiHeight);
            break;
        default:
            break;
    }
}

void SourceImage::Encode(const char *a_pstrFileName, Filetype a_eFiletype, unsigned int a_uiWidth,
                         unsigned int a_uiHeight, unsigned char *a_ptrPixels) {
    switch (a_eFiletype) {
        case Filetype::PNG:
            lodepng_encode32_file(a_pstrFileName, a_ptrPixels, a_uiWidth, a_uiHeight);
            break;
        default:
            break;
    }
}


