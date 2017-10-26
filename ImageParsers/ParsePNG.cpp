//
// Created by meszi on 2017.10.25..
//

#include "ParsePNG.h"

#include <cmath>

ParsePNG::ParsePNG(std::string& fileName, bool& color, float& scale)
        : ImageParser(color, scale), fileName(fileName.c_str()) {
    decodePNG();
    if (color) convertToGreyscale();
    if (scale != 1) resize();
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
    for (unsigned int y = 0; y < height; ++y) {
        for (unsigned int x = 0; x < width; ++x) {
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
    for (unsigned int pixel = 0; pixel < width*height; ++pixel) {
        int red     = image[pixel + 0];
        int green   = image[pixel + 1];
        int blue    = image[pixel + 2];
        auto lightness = (int) floor((0.3 * red) + (0.59 * green) + (0.11 * blue));
        image[pixel + 0] = static_cast<unsigned char>(lightness);
    }
}

void ParsePNG::resize() {
    auto newWidth = (int) std::floor( width * scale);
    auto newHeight = (int) std::floor(height * scale);
    std::vector<unsigned char> newImage;

    if( newWidth < 1 )
    { newWidth = 1; }
    if( newHeight < 1 )
    { newHeight = 1; }
    auto diffY = (int) floor( (height-1.0)/(newHeight-1.0));
    auto diffX = (int) floor( (width-1.0)/(newWidth-1.0));

    for(int y = 0; y < newHeight ; y++){
        for(int x = 0; x < newWidth ; x++){
            newImage.push_back(calculateChunk(x, diffX, y, diffY, 0));
            newImage.push_back(calculateChunk(x, diffX, y, diffY, 1));
            newImage.push_back(calculateChunk(x, diffX, y, diffY, 2));
            newImage.push_back(calculateChunk(x, diffX, y, diffY, 3));
        }
    }
    image = newImage;
    height = static_cast<unsigned int>(newHeight);
    width = static_cast<unsigned int>(newWidth);
}

bool ParsePNG::reachableField(int x, int y) const {
    return !(
            x >= width * 3
            || y >= height * width * 9
            || x < 0
            || y < 0
    );
}

unsigned char ParsePNG::calculateChunk(int x, int diffX, int y, int diffY, int dev) {
    int result = 0;
    int counter = 0;
    int stepY = width * 4;
    int stepX = 4;
    for(int i = -diffY * stepX; i <= diffY * stepY; i += stepY) {
        for(int j = -diffX * stepX; j <= diffX * stepX; j += stepX) {
            if (reachableField(x * stepX + j, y * stepY + i)){
                result += image[y * stepY * diffY + i + x * stepX * diffX + j + dev];
                counter++;
            }
        }
    }
    if(result == 0 ){
        return static_cast<unsigned char>(result);
    }
    return static_cast<unsigned char>(result / counter);
}