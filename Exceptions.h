//
// Created by meszi on 2017.10.26..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_EXCEPTIONS_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_EXCEPTIONS_H

#include <exception>
#include <string>

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

    class UnsupportedExtension : public std::exception {
    public:
        UnsupportedExtension(const std::string &filename) {
            fileName = "Unsupported extension type: " + filename + " !";
        }

        virtual const char* what() const noexcept{
            return fileName.c_str();
        }

    private:
        std::string fileName;
    };
}

namespace parser {
    class BadFileWrite : public std::exception {
    public:
        BadFileWrite(std::string& filename) {
            fileName = "Cannot write to file: " + filename + " !";
        }

        virtual const char* what() const noexcept{
            return fileName.c_str();
        }

    private:
        std::string fileName;
    };
}

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_EXCEPTIONS_H
