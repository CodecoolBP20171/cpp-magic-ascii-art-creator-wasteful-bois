//
// Created by meszi on 2017.10.25..
//

#include "ParsePNG.h"

ParsePNG::ParsePNG(std::string& fileName, bool& color, float& scale)
        : ImageParser(color, scale), fileName(fileName.c_str()) {
    decodePNG();
    if (color) convertToGreyscale();
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
            // Gets the red channel of each pixel, this is sufficient,
            // since all color images' red channel has been updated to contain the
            // lightness value of that pixel
            returnValue += selectCharacter(image[y * width * 4 + x * 4]);
        }
        returnValue += "\n";
    }
    return returnValue;
}

void ParsePNG::convertToGreyscale() {
    for (int pixel = 0; pixel < width*height; ++pixel) {
        int red     = image[pixel + 0];
        int green   = image[pixel + 1];
        int blue    = image[pixel + 2];
        int lightness = (int) floor((0.3 * red) + (0.59 * green) + (0.11 * blue));
        image[pixel + 0] = lightness;
    }
}

void ParsePNG::resize(float &scale) {

}
