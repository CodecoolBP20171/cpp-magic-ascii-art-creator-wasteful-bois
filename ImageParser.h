//
// Created by meszi on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H

#include <string>

class ImageParser {
public:
    virtual std::string const getASCIIToString() = 0;
    virtual void convertToGreyscale() = 0;
    virtual void resize(double &scale) = 0;
};

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSER_H
