//
// Created by meszi on 2017.10.25..
//

#include "ImageParser.h"

const char ImageParser::selectCharacter(const int &lightness) {
    const int threshold = 255 / 16;
    if      (lightness < 1 * threshold)  return Ascii::BLACK;
    else if (lightness < 2 * threshold)  return Ascii::DARK_1;
    else if (lightness < 3 * threshold)  return Ascii::DARK_2;
    else if (lightness < 4 * threshold)  return Ascii::DARK_3;
    else if (lightness < 5 * threshold)  return Ascii::DARK_4;
    else if (lightness < 6 * threshold)  return Ascii::DARK_5;
    else if (lightness < 7 * threshold)  return Ascii::DARK_6;
    else if (lightness < 8 * threshold)  return Ascii::DARK_7;
    else if (lightness < 9 * threshold)  return Ascii::LIGHT_7;
    else if (lightness < 10 * threshold) return Ascii::LIGHT_6;
    else if (lightness < 11 * threshold) return Ascii::LIGHT_5;
    else if (lightness < 12 * threshold) return Ascii::LIGHT_4;
    else if (lightness < 13 * threshold) return Ascii::LIGHT_3;
    else if (lightness < 14 * threshold) return Ascii::LIGHT_2;
    else if (lightness < 15 * threshold) return Ascii::LIGHT_1;
    return Ascii::WHITE;
}

void ImageParser::saveASCIIToFile(const std::string &newFileName) {
    std::ofstream newFile(newFileName);
    if (newFile.is_open()) {
        newFile << getASCIIToString();
        newFile.close();
    } else {
        std::string nonConst(newFileName);
        throw imageExcepction::BadFileWrite(nonConst);
    }
}
