//
// Created by Caste on 2022/5/13.
//
#include "SourceImage.h"
#include "lodepng.h"

using namespace ImageTool;

SourceImage::SourceImage(const char *filename, Filetype type) : m_filename(filename), m_uiWidth(), m_uiHeight(), m_ptr() {
    decode(type);
}


SourceImage::~SourceImage() {
    if (m_ptr != nullptr) {
        free(m_ptr);
    }
}

void SourceImage::decode(Filetype type) {
    if (m_ptr == nullptr) {
        switch (type) {
            case Filetype::PNG:
                lodepng_decode_file(&m_ptr, &m_uiWidth, &m_uiHeight, m_filename, LCT_RGBA, 8);
                break;
            default:
                break;
        }
    }
}

void SourceImage::encode(const char *name) {
    lodepng_encode32_file(name, m_ptr, m_uiWidth, m_uiHeight);
}

void SourceImage::
save(const char *name) {
    int width = m_uiWidth;
    int height = m_uiHeight;
    int channel = 4;
    width = (m_uiWidth + 16 - 1) / 16 * 16;
    height = (m_uiHeight + 4 - 1) / 4 * 4;
    int stride = width * channel;
    int size = width * height * channel;
    uint8_t *new_ptr = (uint8_t *) malloc(size);
    memset(new_ptr, 0, size);
    for (int i = 0; i < height; ++i) {
        if (i < m_uiHeight) {
            for (int j = 0; j < stride; j += channel) {
                if (j < m_uiWidth * channel) {
                    uint32_t r = m_ptr[i * m_uiWidth * channel + j];
                    uint32_t g = m_ptr[i * m_uiWidth * channel + j + 1];
                    uint32_t b = m_ptr[i * m_uiWidth * channel + j + 2];
                    uint32_t a = m_ptr[i * m_uiWidth * channel + j + 3];
                    new_ptr[i * stride + j] = r * a >> 8;
                    new_ptr[i * stride + j + 1] = g * a >> 8;
                    new_ptr[i * stride + j + 2] = b * a >> 8;
                    new_ptr[i * stride + j + 3] = a;
                }
            }
        }
    }
    lodepng_encode32_file(name, new_ptr, width, height);
    free(new_ptr);
}

void SourceImage::save(const char *name, uint32_t width, uint32_t height) {
    int channel = 4;
    int stride = width * channel;
    uint8_t *new_ptr = (uint8_t *) malloc(width * m_uiHeight * channel);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < stride; j += channel) {
            uint32_t r = m_ptr[i * m_uiWidth * channel + j];
            uint32_t g = m_ptr[i * m_uiWidth * channel + j + 1];
            uint32_t b = m_ptr[i * m_uiWidth * channel + j + 2];
            uint32_t a = m_ptr[i * m_uiWidth * channel + j + 3];
            new_ptr[i * stride + j] = r * a >> 8;
            new_ptr[i * stride + j + 1] = g * a >> 8;
            new_ptr[i * stride + j + 2] = b * a >> 8;
            new_ptr[i * stride + j + 3] = a;
        }
    }
    lodepng_encode32_file(name, new_ptr, width, m_uiHeight);
    free(new_ptr);
}

