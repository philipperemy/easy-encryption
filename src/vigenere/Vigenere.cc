#include "Vigenere.h"

using namespace easy::encryption;

int Vigenere::index(char c) {
    for (int i = 0; i < VIGENERE_AVAILABLE_CHARS_SIZE; i++)
        if (VIGENERE_AVAILABLE_CHARS[i] == c)
            return i;
    return -1;
}

std::string Vigenere::extend_key(const std::string &string, const std::string &key) {
    uint64_t stringLen = string.size(), keyLen = key.size();
    std::string newKey(stringLen, 0x0);

    // Generating new key
    for (int i = 0, j = 0; i < stringLen; ++i, ++j) {
        if (j == keyLen) j = 0;
        newKey[i] = key[j];
    }

    return newKey;
}

std::string Vigenere::encrypt(const std::string &decryptedString, const std::string &key) {
    uint64_t decryptedStringLen = decryptedString.size();
    std::string newKey = extend_key(decryptedString, key);
    std::string encryptedString(decryptedStringLen, 0x0);

    // Encryption
    for (int i = 0; i < decryptedStringLen; ++i)
        encryptedString[i] = isalnum(decryptedString[i]) || decryptedString[i] == 0x20 ? VIGENERE_AVAILABLE_CHARS[((index(decryptedString[i]) + index(newKey[i])) % VIGENERE_AVAILABLE_CHARS_SIZE)] : decryptedString[i];

    return encryptedString;
}

std::string Vigenere::decrypt(const std::string &encryptedString, const std::string &key) {
    uint64_t encryptedStringLen = encryptedString.size();
    std::string newKey = extend_key(encryptedString, key);
    std::string decryptedString(encryptedStringLen, 0x0);

    // Decryption
    for (int i = 0; i < encryptedStringLen; ++i)
        decryptedString[i] = isalnum(encryptedString[i]) || encryptedString[i] == 0x20 ? VIGENERE_AVAILABLE_CHARS[(((index(encryptedString[i]) - index(newKey[i])) + VIGENERE_AVAILABLE_CHARS_SIZE) % VIGENERE_AVAILABLE_CHARS_SIZE)] : encryptedString[i];

    return decryptedString;
}
