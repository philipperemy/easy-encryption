#pragma once

#include "base64/Base64.h"
#include "vigenere/Vigenere.h"

using namespace easy::encryption::base64;
using namespace easy::encryption::vigenere;
namespace easy::encryption {
    class EasyEncryption {
    public:
        static std::string encrypt(const std::string &decryptedString, const std::string &key);
        static std::string decrypt(const std::string &encryptedString, const std::string &key);
    };
}
