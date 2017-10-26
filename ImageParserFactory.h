//
// Created by meszi on 2017.10.25..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSERFACTORY_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSERFACTORY_H

#include <stdexcept>
// Included in other includes
// #include "ImageParser.h"
#include "ParseBMP.h"
#include "ParseJPG.h"
#include "ParsePNG.h"
#include "Exceptions.h"

class ImageParserFactory {
public:
    ImageParser *createImageParser(const std::string &fileName, bool &color, float &scale);
    ImageParser *
    createImageParser(const std::string &fileName, const std::string &fileExtension, bool &color, float &scale);

private:
    bool fileExists(const std::string &fileName);
};


#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSERFACTORY_H
