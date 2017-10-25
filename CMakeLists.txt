cmake_minimum_required(VERSION 3.8)
project(cpp_magic_ascii_art_creator_wasteful_bois)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-error=unused-parameter -Werror=unused-variable")

set(SOURCE_FILES
        EasyBMP/EasyBMP.cpp EasyBMP/EasyBMP.h
        EasyBMP/EasyBMP_BMP.h EasyBMP/EasyBMP_DataStructures.h EasyBMP/EasyBMP_VariousBMPutilities.h
        main.cpp ParseBMP.cpp ParseBMP.h LodePNG/LodePNG.cpp LodePNG/LodePNG.h Ascii.h ParsePNG.cpp ParsePNG.h ImageParser.cpp ImageParser.h ImageParserFactory.cpp ImageParserFactory.h)

add_executable(cpp_magic_ascii_art_creator_wasteful_bois ${SOURCE_FILES})