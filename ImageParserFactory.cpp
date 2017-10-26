//
// Created by meszi on 2017.10.25..
//

#include "ImageParserFactory.h"

ImageParser *ImageParserFactory::createImageParser(const std::string &fileName, bool &color, float &scale) {
    if (!fileExists(fileName)) throw factory::FileNotFoundException(fileName);

    std::string nonConstFileName = fileName;
    // TODO: Refactor ParseBMP
    if (fileName.rfind(".bmp") == fileName.length() - 4) return new ParseBMP(nonConstFileName, color, scale);
    if (fileName.rfind(".png") == fileName.length() - 4) return new ParsePNG(nonConstFileName, color, scale);
    if (
            fileName.rfind(".jpg")  == fileName.length() - 4 ||
            fileName.rfind(".jpeg") == fileName.length() - 5
    ) {
        return new ParseJPG(nonConstFileName, color, scale);
    }
    throw factory::UnsupportedFileExtension(fileName);
}

ImageParser *ImageParserFactory::createImageParser(const std::string &fileName, const std::string &fileExtension, bool &color, float &scale) {
    if (!fileExists(fileName)) throw factory::FileNotFoundException(fileName);

    std::string nonConstFileName = fileName;
    // TODO: Refactor ParseBMP
    if (fileExtension == "bmp") return new ParseBMP(nonConstFileName, color, scale);
    if (fileExtension == "png") return new ParsePNG(nonConstFileName, color, scale);
    if (fileExtension == "jpg" || fileExtension == "jpeg") return new ParseJPG(nonConstFileName, color, scale);
    throw factory::UnsupportedFileExtension(fileName);

}

bool ImageParserFactory::fileExists(const std::string &fileName) {
    std::ifstream file;
    file.open(fileName);
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}
