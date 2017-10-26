//
// Created by Joe Bekor on 25/10/2017.
//

#include "ParseJPG.h"

ParseJPG::ParseJPG(std::string &fileName): fileName(fileName.c_str()) {
    decodeJPG();
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

    std::cout << njDecode(buffer, result) << std::endl;
    width =  njGetWidth();
    height = njGetHeight();
    image = njGetImage();

    // terminate
    fclose (pFile);
    free (buffer);

}

const std::string ParseJPG::getASCIIToString() {
    std::string returnValue;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int red     = image[y * width * 3 + x * 3 + 0];
            int green   = image[y * width * 3 + x * 3 + 1];
            int blue    = image[y * width * 3 + x * 3 + 2];
            int lightness = (0.3 * red) + (0.59 * green) + (0.11 * blue);
            returnValue += selectCharacter(lightness);
        }
        returnValue += "\n";
    }
    return returnValue;
}

void ParseJPG::saveASCIIToFile(const std::string &newFileName) {

}

void ParseJPG::convertToGreyscale() {

}

void ParseJPG::resize(double &scale) {

}
