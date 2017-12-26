#include "b64.h"
#include "vigenere.h"

std::string encrypt(std::string& msg, std::string& key) {
	std::string vigenere_msg = encrypt_vigenere(msg, key);
	// std::cout << vigenere_msg << std::endl;
	return base64_encode(vigenere_msg);
}


std::string decrypt(std::string& encrypted_msg, std::string& key) {
	std::string newKey = extend_key(encrypted_msg, key);
	std::string b64_decode_str = base64_decode(encrypted_msg);
	return decrypt_vigenere(b64_decode_str, newKey);
}