//
// Created by meszi on 2017.10.25..
//

#include "ImageParser.h"

const char const ImageParser::selectCharacter(const int &lightness) {
    const int threshold = 255 / 8;
    if      (lightness < 1 * threshold) return Ascii::BLACK;
    else if (lightness < 2 * threshold) return Ascii::DARK_1;
    else if (lightness < 3 * threshold) return Ascii::DARK_2;
    else if (lightness < 4 * threshold) return Ascii::MEDIUM_DARK;
    else if (lightness < 5 * threshold) return Ascii::MEDIUM_LIGHT;
    else if (lightness < 6 * threshold) return Ascii::LIGHT_2;
    else if (lightness < 7 * threshold) return Ascii::LIGHT_1;
    return Ascii::WHITE;
}
