//
// Created by Joe Bekor on 25/10/2017.
//

#include "ParseJPG.h"

ParseJPG::ParseJPG(std::string& fileName, bool& color, float& scale)
        : ImageParser(color, scale), fileName(fileName.c_str()) {
    decodeJPG();
    if(color) convertToGreyscale();
//    if(scale != 1) resize();
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
    image = njGetImage();
    // terminate
    fclose (pFile);
    free (buffer);

}

const std::string ParseJPG::getASCIIToString() {
    std::string returnValue;
    std::cout << " height " << height << " width " << width << std::endl;
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
    int newWidth = (int) floor( width * scale);
    int newHeight = (int) floor( height * scale);
    unsigned char *newImage = new unsigned char[newWidth * newHeight * 9];

    if( newWidth < 1 )
    { newWidth = 1; }
    if( newHeight < 1 )
    { newHeight = 1; }
    std::cout << "current : " << newWidth * newHeight << std::endl;
    int diffY = (int) floor(  (double)((height-1.0))/(double)(newHeight-1.0));
    int diffX = (int) floor(  (double)((width-1.0))/(double)(newWidth-1.0));

    for(int y = 0; y < newHeight ; y++){
        for(int x = 0; x < newWidth ; x++){
            newImage[y * newWidth * 3 + x * 3 + 0] = calculateChunk(x, diffX, y, diffY, 0);
            newImage[y * newWidth * 3 + x * 3 + 1] = calculateChunk(x, diffX, y, diffY, 1);
            newImage[y * newWidth * 3 + x * 3 + 2] = calculateChunk(x, diffX, y, diffY, 2);
        }
    }
    image = newImage;
    height = newHeight;
    width = newWidth;
    delete[] newImage;
}

bool ParseJPG::reachableField(int x, int y) const {
    return !(
            x >= width * 3
            || y >= height * width * 9
            || x < 0
            || y < 0
    );
}

unsigned char ParseJPG::calculateChunk(int x, int diffX, int y, int diffY, int dev) {
    int result = 0;
    int counter = 0;
    int stepY = width * 3;
    int stepX = 3;
    for(int i = -diffY * stepY; i <= diffY * stepY; i += stepY) {
        for(int j = -diffX * stepX; j <= diffX * stepX; j += stepX) {
            if (reachableField(j,i)){
                result += image[y * stepY + i + x * stepX + j + dev];
                counter++;
            }
        }
    }
    if(result == 0 ){
        return static_cast<unsigned char>(result);
    }
    return static_cast<unsigned char>(result / counter);
}
