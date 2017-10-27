//
// Created by meszi on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H

#include <fstream>
#include <cmath>
#include <string>
#include "../Ascii.h"
#include "../Exceptions.h"

class ImageParser {
public:
    ImageParser() : color(false), scale(1.0) {}
    ImageParser(bool& isColored, float& scale) : color(isColored), scale(scale) {}

    virtual std::string const getASCIIToString() = 0;
    virtual void saveASCIIToFile(const std::string &newFileName) final;

protected:
    const bool color;
    const float scale;
    const char selectCharacter(const int &lightness);
    virtual void convertToGreyscale() = 0;
    virtual void resize() = 0;
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H
