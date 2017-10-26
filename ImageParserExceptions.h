//
// Created by meszi on 2017.10.26..
//

#ifndef CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSEREXCEPTIONS_H
#define CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSEREXCEPTIONS_H

#include <exception>
#include <string>

namespace imageExcepction {
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

#endif //CPP_MAGIC_ASCII_ART_CREATOR_WASTEFUL_BOIS_IMAGEPARSEREXCEPTIONS_H
