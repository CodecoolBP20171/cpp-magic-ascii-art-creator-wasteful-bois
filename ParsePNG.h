//
// Created by meszi on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEPNG_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEPNG_H

#include <iostream>
#include "LodePNG/LodePNG.h"
#include "ImageParser.h"
#include "Ascii.h"

class ParsePNG : public ImageParser{
public:
    ParsePNG(std::string& fileName);

    const std::string getASCIIToString() override;

private:
    std::vector<unsigned char> image;
    const char* fileName;
    unsigned width;
    unsigned height;

    void decodePNG();

    void convertToGreyscale() override;
    void resize(float &scale) override;
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEPNG_H
