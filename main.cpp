//
// Created by bekor on 10/24/17.
//

#include <iostream>
#include <vector>
#include "Converter.h"


void showUsage(std::string name);
// Still template
int main(int argc, char* argv[])
{
    if (argc < 3) {
        showUsage(argv[0]);
        return 1;
    }
    std::vector <std::string> sources;
    std::string filename;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            showUsage(argv[0]);
            return 0;
        } else if ((arg == "-f") || (arg == "--file")) {
            if (i + 1 < argc) {
                filename = argv[++i];
                sources.push_back(filename.substr(0, filename.find('.')+1));
                sources.push_back(filename.substr(filename.find('.')+1));
            } else {
                std::cerr << "--file option requires one argument." << std::endl;
                return 1;
            }
        } else {
            // Later, for other arguments.
            sources.push_back("");
            sources.push_back("");
        }
    }
    //Error handling?
    std::cout << sources[0] << " and " << sources[1] << std::endl;
    Converter c;
    c.convertPics(sources);
    std::string output = c.getASCIIString();
    std::cout << output << std::endl;
    return 0;
}

void showUsage(std::string name) {
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-f,--file FILE NAME\tSpecify the file name"
              << std::endl;
}
