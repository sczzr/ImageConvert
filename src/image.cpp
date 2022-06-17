//
// Created by Caste on 2022/5/27.
//

#include "image.h"
#include "sourceimage.h"
#include "resource.h"

namespace ImageTool
{
Image::Image(const char *a_pstrFileName)
{
	General::Resource source(a_pstrFileName);
	m_SourceImage = new SourceImage(source.FilePath(), GetType(source.FileType()));
}

Image::~Image()
{
	if (m_SourceImage)
	{
		delete m_SourceImage;
	}
}

int
Image::Read(int a_iPixelX, int a_iPixelY)
{
	return 0;
}

int
Image::ReadRaw(ImageType::Filetype a_eType, int a_iPixelX, int a_iPixelY)
{
	return 0;
}

int
Image::Save(const char *a_pstrFilename, ImageType::Filetype a_efileType)
{
	return 0;
}

int
Image::Save(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiWidth, unsigned int a_uiHeight)
{
	m_SourceImage->Encode(a_pstrFilename, a_efileType, a_uiWidth, a_uiHeight);
	return 1;
}

int
Image::SaveAlign(const char *a_pstrFilename, Filetype a_efileType, unsigned int a_uiHAlignCoef,
				 unsigned int a_uiVAlignCoef,
				 const General::Color &a_rCFillColor)
{
	int sourceWidth = m_SourceImage->Width();
	int sourceHeight = m_SourceImage->Height();
	unsigned char *sourcePixels = m_SourceImage->Pixels();
	int width = (sourceWidth + a_uiHAlignCoef - 1) / a_uiHAlignCoef * a_uiHAlignCoef;
	int height = (sourceHeight + a_uiVAlignCoef - 1) / a_uiVAlignCoef * a_uiVAlignCoef;

	int channel = 4;
	int stride = width * channel;
	int size = width * height * channel;
	uint8_t *new_ptr = (uint8_t *)malloc(size);
	memset(new_ptr, 0, size);
	for (int i = 0; i < height; ++i)
	{
		if (i < sourceHeight)
		{
			for (int j = 0; j < stride; j += channel)
			{
				if (j < sourceWidth * channel)
				{
					uint32_t r = sourcePixels[i * sourceWidth * channel + j];
					uint32_t g = sourcePixels[i * sourceWidth * channel + j + 1];
					uint32_t b = sourcePixels[i * sourceWidth * channel + j + 2];
					uint32_t a = sourcePixels[i * sourceWidth * channel + j + 3];
					new_ptr[i * stride + j] = r;
					new_ptr[i * stride + j + 1] = g;
					new_ptr[i * stride + j + 2] = b;
					new_ptr[i * stride + j + 3] = a;
				}
			}
		}
	}
	m_SourceImage->Encode(a_pstrFilename, a_efileType, width, height, new_ptr);
	free(new_ptr);
	return 1;
}

int
Image::SavePreMulAlphaWithAlign(const char *a_pstrFilename, ImageType::Filetype a_efileType,
								unsigned int a_uiHAlignCoef, unsigned int a_uiVAlignCoef,
								const General::Color &a_rCFillColor)
{
	int sourceWidth = m_SourceImage->Width();
	int sourceHeight = m_SourceImage->Height();
	unsigned char *sourcePixels = m_SourceImage->Pixels();
	int width = (sourceWidth + a_uiHAlignCoef - 1) / a_uiHAlignCoef * a_uiHAlignCoef;
	int height = (sourceHeight + a_uiVAlignCoef - 1) / a_uiVAlignCoef * a_uiVAlignCoef;

	int channel = 4;
	int stride = width * channel;
	int size = width * height * channel;
	uint8_t *new_ptr = (uint8_t *)malloc(size);
	memset(new_ptr, 0, size);
	memcpy(new_ptr, sourcePixels, sourceHeight * sourceWidth);
        for (int i = 0; i < height; ++i) {
            if (i < sourceHeight) {
                for (int j = 0; j < stride; j += channel) {
                    if (j < sourceWidth * channel) {
                        uint32_t r = sourcePixels[i * sourceWidth * channel + j];
                        uint32_t g = sourcePixels[i * sourceWidth * channel + j + 1];
                        uint32_t b = sourcePixels[i * sourceWidth * channel + j + 2];
                        uint32_t a = sourcePixels[i * sourceWidth * channel + j + 3];
                        new_ptr[i * stride + j] = r * a >> 8;
                        new_ptr[i * stride + j + 1] = g * a >> 8;
                        new_ptr[i * stride + j + 2] = b * a >> 8;
                        new_ptr[i * stride + j + 3] = a;
                    }
                }
            }
        }
	m_SourceImage->Encode(a_pstrFilename, a_efileType, width, height, new_ptr);
	free(new_ptr);
	return 1;
}
} // ImageTool