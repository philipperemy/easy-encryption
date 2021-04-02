cmake_minimum_required(VERSION 3.5)
project(easy_encryption)

option(EASY_ENCRYPTION_EXAMPLES "Build examples?" ON)

add_library(${PROJECT_NAME} src/base64/Base64.cc src/vigenere/Vigenere.cc src/EasyEncryption.cc)
target_include_directories(${PROJECT_NAME} PRIVATE ${SRC_DIR})

if(EASY_ENCRYPTION_EXAMPLES)
    add_subdirectory(examples)
endif()
