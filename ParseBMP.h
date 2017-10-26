//
// Created by bekor on 10/24/17.
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEBMP_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEBMP_H


#include <vector>
#include "EasyBMP/EasyBMP.h"
#include "ImageParser.h"

class ParseBMP : public ImageParser{
public:
    ParseBMP(const std::string &fileName, bool &color, float &scale);

    const std::string getASCIIToString() override;

private:
    BMP image;
    const char* fileName;
    unsigned width;
    unsigned height;

    void decodeBMP();

    void convertToGreyscale() override;
    void resize() override;

};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_PARSEBMP_H
