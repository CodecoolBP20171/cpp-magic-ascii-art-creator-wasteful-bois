//
// Created by bekor on 10/24/17.
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEBMP_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEBMP_H


#include "EasyBMP/EasyBMP.h"
#include "Converter.h"

const char BLACK = '@';
const char CHARCOAL = '#';
const char DARKGRAY = '8';
const char MEDIUMGRAY = '&';
const char MEDIUM = 'o';
const char GRAY = ':';
const char SLATEGRAY = '*';
const char LIGHTGRAY = '.';
const char WHITE = ' ';

class ParseBMP {

public:
    void ScaleBMP(std::string &asciiString, std::string &inputImageName);
    void PrintCharTable(std::string &asciiString, BMP& InputImage );

private:

};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEBMP_H
