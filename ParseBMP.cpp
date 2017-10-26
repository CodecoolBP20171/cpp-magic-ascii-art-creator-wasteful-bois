//
// Created by bekor on 10/24/17.
//

#include "ParseBMP.h"

ParseBMP::ParseBMP(const std::string &fileName, bool &color, float &scale)
        : ImageParser(color, scale), fileName(fileName.c_str())   {
    decodeBMP();
    if(color) convertToGreyscale();
    if(scale != 1) resize();
}

void ParseBMP::decodeBMP() {
    image.ReadFromFile(fileName);
    image.SetBitDepth(8);
    height = static_cast<unsigned int>(image.TellHeight());
    width = static_cast<unsigned int>(image.TellWidth());
}

const std::string ParseBMP::getASCIIToString() {
    std::string returnValue;
    for( int j=0 ; j < height ; j ++) {
        for (int i = 0; i <width; i++) {
            returnValue += selectCharacter(image(i,j)->Red);
        }
        returnValue += "\n";
    }
    return returnValue;
}

void ParseBMP::convertToGreyscale() {
    CreateGrayscaleColorTable(image);
}

void ParseBMP::resize() {
    int reScale = (int)(scale*100);
    Rescale(image, 'p', reScale);
    height = static_cast<unsigned int>(image.TellHeight());
    width = static_cast<unsigned int>(image.TellWidth());
}
