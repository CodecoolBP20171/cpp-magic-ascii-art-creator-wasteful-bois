//
// Created by Joe Bekor on 25/10/2017.
//
extern "C" {
    #include "NanoJPG/nanojpeg.h"
}
#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEJPG_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEJPG_H

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "ImageParser.h"
#include "Ascii.h"

class ParseJPG: public ImageParser {
public:
    ParseJPG(std::string& fileName, bool& color, float& scale);

    const std::string getASCIIToString() override;

private:
    std::vector<unsigned char> image;
    const char* fileName;
    int width;
    int height;

    void decodeJPG();

    void convertToGreyscale() override;
    void resize(float &scale) override;
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEJPG_H
