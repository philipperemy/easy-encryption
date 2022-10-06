#include "Base64.h"
#include "vigenere.h"

std::string encrypt(std::string& msg, std::string& key)
{
    std::vector<char> msg2(msg.begin(), msg.end());
    std::string b64_str = Base64::encode(msg2);
    std::string vigenere_msg = encrypt_vigenere(b64_str, key);
    return vigenere_msg;
}


std::string decrypt(std::string& encrypted_msg, std::string& key)
{
    std::string newKey = extend_key(encrypted_msg, key);
    std::string b64_encoded_str = decrypt_vigenere(encrypted_msg, newKey);
    std::vector<char> b64_decode_vec = Base64::decode(b64_encoded_str);
    std::string b64_decode_str(b64_decode_vec.begin(), b64_decode_vec.end());
    return b64_decode_str;
}
