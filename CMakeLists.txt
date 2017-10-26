cmake_minimum_required(VERSION 3.8)
project(cpp_magic_ascii_art_creator_wasteful_bois)

set(CMAKE_CXX_STANDARD 11)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wno-error=unused-parameter -Werror=unused-variable")

set(SOURCE_FILES
        EasyBMP/EasyBMP.cpp EasyBMP/EasyBMP.h
        EasyBMP/EasyBMP_BMP.h EasyBMP/EasyBMP_DataStructures.h EasyBMP/EasyBMP_VariousBMPutilities.h
        LodePNG/LodePNG.cpp LodePNG/LodePNG.h
        NanoJPG/nanojpeg.h NanoJPG/nanojpeg.c
        Ascii.h
        ImageParser.cpp ImageParser.h
        ImageParserFactory.cpp ImageParserFactory.h
        ParseJPG.cpp ParseJPG.h
        ParseBMP.cpp ParseBMP.h
        ParsePNG.cpp ParsePNG.h
        main.cpp)

add_executable(cpp_magic_ascii_art_creator_wasteful_bois ${SOURCE_FILES})