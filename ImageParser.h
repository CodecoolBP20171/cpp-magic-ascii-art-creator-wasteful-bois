//
// Created by meszi on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H

#include <fstream>
#include <string>
#include "Ascii.h"
#include "ImageParserExceptions.h"

class ImageParser {
public:
    ImageParser() : isColored(false), scale(1.0) {}
    ImageParser(bool& isColored, float& scale) : isColored(isColored), scale(scale) {}

    virtual std::string const getASCIIToString() = 0;
    virtual void saveASCIIToFile(const std::string &newFileName) final;

protected:
    bool isColored;
    float scale;
    virtual const char selectCharacter(const int &lightness) final;

private:
    virtual void convertToGreyscale() = 0;
    virtual void resize(float &scale) = 0;
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H
