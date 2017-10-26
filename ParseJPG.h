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
    unsigned char* image;
    const char* fileName;
    int width;
    int height;

    void decodeJPG();

    void convertToGreyscale() override;
    void resize() override;
    unsigned char calculateChunk(int x, int diffX, int y, int diffY, int dev);
    bool reachableField(int x, int y) const;
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEJPG_H
