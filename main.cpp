//
// Created by bekor on 10/24/17.
//

#include <iostream>
#include <vector>
#include "EasyBMP/EasyBMP.h"



void showUsage(std::string name);
// Still template
int main(int argc, char* argv[])
{
    if (argc < 3) {
        showUsage(argv[0]);
        return 1;
    }
    std::vector <std::string> sources;
    std::string destination;
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if ((arg == "-h") || (arg == "--help")) {
            showUsage(argv[0]);
            return 0;
        } else if ((arg == "-d") || (arg == "--destination")) {
            if (i + 1 < argc) { // Make sure we aren't at the end of argv!
                destination = argv[i++]; // Increment 'i' so we don't get the argument as the next argv[i].
            } else { // Uh-oh, there was no argument to the destination option.
                std::cerr << "--destination option requires one argument." << std::endl;
                return 1;
            }
        } else {
            sources.push_back(argv[i]);
        }
    }
//    return move(sources, destination);
    return 0;
}

void showUsage(std::string name) {
    std::cerr << "Usage: " << name << " <option(s)> SOURCES"
              << "Options:\n"
              << "\t-h,--help\t\tShow this help message\n"
              << "\t-d,--destination DESTINATION\tSpecify the destination path"
              << std::endl;
}
