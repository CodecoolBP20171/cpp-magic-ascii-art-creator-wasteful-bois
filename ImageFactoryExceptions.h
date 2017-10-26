//
// Created by meszi on 2017.10.26..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEFACTORYEXCEPTIONS_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEFACTORYEXCEPTIONS_H

#include "exception"

namespace factory {
    class FileNotFoundException : public std::exception {
    public:
        FileNotFoundException(const std::string &filename) {
            fileName = "File not found: " + filename + " !";
        }

        virtual const char* what() const noexcept {
            return fileName.c_str();
        }

    private:
        std::string fileName;
    };

    class UnsupportedFileExtension : public std::exception {
    public:
        UnsupportedFileExtension(const std::string &filename) {
            fileName = "Unsupported extension type: " + filename + " !";
        }

        virtual const char* what() const noexcept{
            return fileName.c_str();
        }

    private:
        std::string fileName;
    };
}

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEFACTORYEXCEPTIONS_H
