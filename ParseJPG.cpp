//
// Created by Joe Bekor on 25/10/2017.
//

#include "ParseJPG.h"

ParseJPG::ParseJPG(std::string& fileName, bool& color, float& scale)
        : ImageParser(color, scale), fileName(fileName.c_str()) {
    decodeJPG();
    if(color) convertToGreyscale();

}

void ParseJPG::decodeJPG() {
    // TODO: Cleaning ?

    FILE * pFile;
    long lSize;
    char * buffer;
    size_t result;

    pFile = fopen ( fileName , "rb" );
    if (pFile==NULL) {fputs ("File error",stderr); exit (1);}

    // obtain file size:
    fseek (pFile , 0 , SEEK_END);
    lSize = ftell (pFile);
    rewind (pFile);

    // allocate memory to contain the whole file:
    buffer = (char*) malloc (sizeof(char)*lSize);
    if (buffer == NULL) {fputs ("Memory error",stderr); exit (2);}
    // copy the file into the buffer:
    result = fread (buffer,1,lSize,pFile);
    if (result != lSize) {fputs ("Reading error",stderr); exit (3);}
    /* the whole file is now loaded in the memory buffer. */

    njInit();

    std::cout << njDecode(buffer, static_cast<const int>(result)) << std::endl;
    width =  njGetWidth();
    height = njGetHeight();
    unsigned char *imageRaw = njGetImage();

    for (int i = 0; i < width*height; ++i) {
        image[i] = imageRaw[i];
    }

    // terminate
    fclose (pFile);
    free (buffer);

}

const std::string ParseJPG::getASCIIToString() {
    std::string returnValue;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            returnValue += selectCharacter(image[y * width * 3 + x * 3 + 0]);
        }
        returnValue += "\n";
    }
    return returnValue;
}

void ParseJPG::convertToGreyscale() {
    for (int pixel = 0; pixel < width*height; ++pixel) {
        int red     = image[pixel + 0];
        int green   = image[pixel + 1];
        int blue    = image[pixel + 2];
        int lightness = (int) floor((0.3 * red) + (0.59 * green) + (0.11 * blue));
        image[pixel + 0] = lightness;
    }
}

void ParseJPG::resize() {

}
