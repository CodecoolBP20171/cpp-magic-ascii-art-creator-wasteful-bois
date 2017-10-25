//
// Created by bekor on 10/25/17.
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_CONVERTER_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_CONVERTER_H

#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include "ParseBMP.h"

class Converter {
public:
    void convertPics(std::vector<std::string> &filename);
    std::string getASCIIString() { return  ASCIIString; };
    std::string ASCIIString;

private:
    const std::string fileFormats[3] = {"bmp", "png", "jpeg"};

    int fileTypeIsValid(std::string &pString);
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_CONVERTER_H
