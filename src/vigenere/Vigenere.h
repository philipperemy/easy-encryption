#pragma once

#include "../EasyEncryptionConsts.h"

namespace easy {
    namespace encryption {
        namespace vigenere {
            class Vigenere {
            public:
                static std::string extend_key(const std::string &string, const std::string &key);
                static std::string encrypt(const std::string &decryptedString, const std::string &key);
                static std::string decrypt(const std::string &encryptedString, const std::string &key);
            private:
                static int index(char c);
            };
        }
    }
}
