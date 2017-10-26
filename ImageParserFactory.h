//
// Created by meszi on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSERFACTORY_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSERFACTORY_H

#include <stdexcept>
// Included in other includes
// #include "ImageParser.h"
#include "ParseBMP.h"
#include "ParsePNG.h"

class ImageParserFactory {
public:
    ImageParser* createImageParser(const std::string& fileName);

private:
    bool isExistingFile(const std::string& fileName);
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSERFACTORY_H
