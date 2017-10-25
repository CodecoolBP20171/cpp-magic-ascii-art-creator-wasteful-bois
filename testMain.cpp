//
// Created by meszi on 2017.10.25..
//

#include "ParsePNG.h"

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;

    std::string filename = argv[1];
    ParsePNG pngImage(filename);

    return 0;
}