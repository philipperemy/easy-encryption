#include "b64.h"
#include "vigenere.h"

std::string encrypt(std::string& msg, std::string& key) {
	std::string b64_str = base64_encode(msg);
	std::string vigenere_msg = encrypt_vigenere(b64_str, key);
	// std::cout << vigenere_msg << std::endl;
	return vigenere_msg;
}


std::string decrypt(std::string& encrypted_msg, std::string& key) {
	std::string newKey = extend_key(encrypted_msg, key);
	std::string b64_encoded_str = decrypt_vigenere(encrypted_msg, newKey);
	std::string b64_decode_str = base64_decode(b64_encoded_str);
	return b64_decode_str;
}