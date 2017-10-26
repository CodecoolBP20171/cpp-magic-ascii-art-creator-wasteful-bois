//
// Created by meszi on 2017.10.26..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEFACTORYEXCEPTIONS_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEFACTORYEXCEPTIONS_H

#include "exception"

namespace factory {
    class FileNotFoundException : public std::exception {
    public:
        FileNotFoundException(const std::string &filename) : fileName(fileName) {}

        virtual const char* what() const noexcept {
            std::string str("File not found: ");
            str += fileName;
            str += "!";
            return str.c_str();
        }

    private:
        const std::string fileName;
    };

    class UnsupportedFileExtension : public std::exception {
    public:
        UnsupportedFileExtension(const std::string &fileName) : fileName(fileName) {}

        virtual const char* what() const noexcept{
            std::string str("File extension not supported: ");
            str += fileName;
            str += "!";
            return str.c_str();
        }

    private:
        const std::string fileName;
    };
}

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEFACTORYEXCEPTIONS_H
