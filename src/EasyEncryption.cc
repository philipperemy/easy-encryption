#include "EasyEncryption.h"

using namespace easy::encryption;

std::string EasyEncryption::encrypt(const std::string &decryptedString, const std::string &key) {
    // Encrypt first as Base64
    const std::string b64_encoded_str = Base64::encode(decryptedString);

    // Last encryption, vigenere
    std::string vigenere_encoded_str = Vigenere::encrypt(b64_encoded_str, key);

    return vigenere_encoded_str;
}

std::string EasyEncryption::decrypt(const std::string &encryptedString, const std::string &key) {
    // Decrypt firstly, the vigenere
    const std::string vigenere_decoded_str = Vigenere::decrypt(encryptedString, key);

    // Then decrypt the base 64
    std::string b64_decoded_str = Base64::decode(vigenere_decoded_str);

    return b64_decoded_str;
}
