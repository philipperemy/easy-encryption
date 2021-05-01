cmake_minimum_required(VERSION 3.19)
project(easy_encryption)

option(EASY_ENCRYPTION_EXAMPLES "Build examples?" ON)

set(CMAKE_CXX_STANDARD 98)

add_library(${PROJECT_NAME} STATIC src/base64/Base64.cc src/vigenere/Vigenere.cc src/EasyEncryption.cc)

if(EASY_ENCRYPTION_EXAMPLES)
    add_subdirectory(examples)
endif(EASY_ENCRYPTION_EXAMPLES)
