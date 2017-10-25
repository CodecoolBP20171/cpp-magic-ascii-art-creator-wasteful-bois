//
// Created by meszi on 2017.10.25..
//

#include "ParsePNG.h"

ParsePNG::ParsePNG(std::string &fileName) : fileName(fileName.c_str()) {
    decodePNG();
}

void ParsePNG::decodePNG() {
    unsigned error = lodepng::decode(image, width, height, fileName);

    if (error) {
        std::cout << "Error while decoding PNG image:" << std::endl
                  << error << ": " << lodepng_error_text(error) << std::endl;
    }
}

// ImageParser overrides
const std::string ParsePNG::getASCIIToString() {
    std::string returnValue;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int red     = image[y * width * 4 + x * 4 + 0];
            int green   = image[y * width * 4 + x * 4 + 1];
            int blue    = image[y * width * 4 + x * 4 + 2];
            int lightness = (0.3 * red) + (0.59 * green) + (0.11 * blue);
            returnValue += selectCharacter(lightness);
        }
        returnValue += "\n";
    }
    return returnValue;
}

void ParsePNG::convertToGreyscale() {

}

void ParsePNG::resize(double &scale) {

}
