//
// Created by Caste on 2022/5/31.
//

#ifndef PNGTOOL_COLOR_H
#define PNGTOOL_COLOR_H

namespace General {

    class Color {
    public:
        Color();
        Color(unsigned int a_uiColor);
    private:
        unsigned int m_uiColor;
    };

    class RGBA8888 : public Color {
    public:
        unsigned char ucR;
        unsigned char ucG;
        unsigned char ucB;
        unsigned char ucA;
    };
} // General

#endif //PNGTOOL_COLOR_H
