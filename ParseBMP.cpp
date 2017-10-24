//
// Created by bekor on 10/24/17.
//

#include "ParseBMP.h"

void ParseBMP::ScaleBMP(std::string inputImageName) {
    const char * c = inputImageName.c_str();
    BMP Text;
    Text.ReadFromFile(c);
    Text.SetBitDepth(8);
    CreateGrayscaleColorTable(Text);
    std::cout << "colors: " << Text.TellNumberOfColors() << std::endl;
    Rescale(Text, 'p', 40);
    PrintCharTable( Text );
}

// Should be shortened using modulo, and chosing char from a list or something.
void ParseBMP::PrintCharTable( BMP& InputImage )
{
    for( int j=0 ; j < InputImage.TellHeight() ; j ++)
    {
        for( int i=0 ; i < InputImage.TellWidth() ; i ++)
        {
            if(InputImage(i,j)->Red < 28){
                InputImage(i,j)->Red = BLACK;
                InputImage(i,j)->Blue = BLACK;
                InputImage(i,j)->Green = BLACK;
            } else if ( 28 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 56){
                InputImage(i,j)->Red = CHARCOAL;
                InputImage(i,j)->Blue = CHARCOAL;
                InputImage(i,j)->Green = CHARCOAL;
            } else if ( 56 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 84){
                InputImage(i,j)->Red = DARKGRAY;
                InputImage(i,j)->Blue = DARKGRAY;
                InputImage(i,j)->Green = DARKGRAY;
            } else if ( 84 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 112){
                InputImage(i,j)->Red = MEDIUMGRAY;
                InputImage(i,j)->Blue = MEDIUMGRAY;
                InputImage(i,j)->Green = MEDIUMGRAY;
            } else if ( 112 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 140){
                InputImage(i,j)->Red = MEDIUM;
                InputImage(i,j)->Blue = MEDIUM;
                InputImage(i,j)->Green = MEDIUM;
            } else if ( 140 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 168){
                InputImage(i,j)->Red = GRAY;
                InputImage(i,j)->Blue = GRAY;
                InputImage(i,j)->Green = GRAY;
            } else if ( 168 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 196){
                InputImage(i,j)->Red = SLATEGRAY;
                InputImage(i,j)->Blue = SLATEGRAY;
                InputImage(i,j)->Green = SLATEGRAY;
            } else if ( 196 <= InputImage(i,j)->Red && InputImage(i,j)->Red < 224){
                InputImage(i,j)->Red = LIGHTGRAY;
                InputImage(i,j)->Blue = LIGHTGRAY;
                InputImage(i,j)->Green = LIGHTGRAY;
            } else{
                InputImage(i,j)->Red = WHITE;
                InputImage(i,j)->Blue = WHITE;
                InputImage(i,j)->Green = WHITE;
            }
            std::cout<< InputImage(i,j)->Red;
        }
        std::cout << std::endl;
    }
}
