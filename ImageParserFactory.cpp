//
// Created by meszi on 2017.10.25..
//

#include "ImageParserFactory.h"

ImageParser *ImageParserFactory::createImageParser(const std::string &fileName) {
    if (!isExistingFile(fileName)) {
        throw std::invalid_argument("File not found: " + fileName + "!");
    }
    std::string nonConstFileName = fileName;
    // Refactor ParseBMP
    if (fileName.find(".bmp") == fileName.length() - 4) return nullptr;
    if (fileName.find(".png") == fileName.length() - 4) return new ParsePNG(nonConstFileName);
    if (
            fileName.find(".jpg")  == fileName.length() - 4 ||
            fileName.find(".jpeg") == fileName.length() - 5
    ) {
//        return new ParseJPG(fileName);
        return nullptr;
    }
    return nullptr;
}

bool ImageParserFactory::isExistingFile(const std::string &fileName) {
    // If no extension is given, try to open file with all three extensions, if all fail, return false
    // If extension is given, only try with that.
    return false;
}
