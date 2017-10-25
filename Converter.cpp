//
// Created by bekor on 10/25/17.
//

#include "Converter.h"

void Converter::convertPics(std::vector<std::string> &filename) {
    if(filename.size() < 3){
        int fileFormat = fileTypeIsValid(filename.at(1));
        if(fileFormat){
            std::string s = "../pics/";
            s += filename.at(0);
            s += filename.at(1);
            switch(fileFormat){
                case 1:
                    ParseBMP fishy;
                    fishy.ScaleBMP(this->ASCIIString, s);
                    break;
                case 2:
                    break;
                case 3:
                    break;
                default:
                    break;
            }
        }
    }
}

int Converter::fileTypeIsValid(std::string &format) {
    for(int i = 0; i < fileFormats->size(); ++i){
        if(fileFormats[i] == format){
            return i+1;
        }
    }
    return 0;
}


