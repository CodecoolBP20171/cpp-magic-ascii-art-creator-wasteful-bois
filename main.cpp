//
// Created by bekor on 10/24/17.
//

#include <iostream>
#include <vector>
#include "ImageParserFactory.h"


void showUsage(const char* name);

int main(int argc, char* argv[])
{
    if (argc < 3) {
        showUsage(argv[0]);
        return 1;
    }
    std::string filename;
    std::string fileType;
    bool fileColored = false;
    float scaleFactor = 1;

    std::vector <std::string> sources;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            showUsage(argv[0]);
            return 0;
        } else if ((arg == "-f") || (arg == "--file")) {
            if (i + 1 < argc) {
                filename = argv[++i];
                fileType = filename.substr(filename.rfind('.')+1);
            } else {
                std::cerr << "--file option requires one argument." << std::endl;
                return 1;
            }
        } else if ((arg == "-c") || (arg == "--color")) {
            fileColored = true;
        } else if ((arg == "-r") || (arg == "--resize")) {
            if(i + 1 < argc) {
                scaleFactor = std::stof(argv[++i]);
            } else {
                std::cerr << "--resize option requires one argument." << std::endl;
                return 1;
            }
        }
    }
    //Error handling?

    ImageParserFactory imageFactory;
    ImageParser *imageParser;
    try {
        imageParser = imageFactory.createImageParser(filename, fileType, fileColored, scaleFactor);
    } catch (factory::FileNotFoundException& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    } catch (factory::UnsupportedExtension& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    std::cout << imageParser->getASCIIToString();
    try {
        imageParser->saveASCIIToFile("../test.txt");
    } catch (imageExcepction::BadFileWrite& e) {
        std::cerr << e.what() << std::endl;
    }
    delete imageParser;

    return 0;
}

void showUsage(const char* name) {
    std::cerr << "Usage: " << name << " <option(s)>\n"
              << "Options:\n"
              << "\t-h,--help\t\t\t| Show this help message\n"
              << "\t-f,--file FILE NAME\t| Specify the file name\n"
              << "\t-c,--color \t\t\t| If image is colored\n"
              << "\t-r,--resize VALUE\t| Specify the scale between 0 - 1 (eg. 0.5)"
              << std::endl;
}
