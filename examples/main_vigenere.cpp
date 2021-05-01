#include <iostream>
#include "../src/vigenere/Vigenere.h"

using namespace easy::encryption;

int main() {
	// Vigenere encoding
    std::string msg = "HELLO WORLD";
    std::string key = "THISISALONGPRIVATEKEY";

    std::string encryptedMsg = Vigenere::encrypt(msg, key);
    std::string newKey = Vigenere::extend_key(msg, key);
    std::string decryptedMsg = Vigenere::decrypt(encryptedMsg, newKey);

 	std::cout << "Original Message : " << msg << std::endl;
 	std::cout << "Key              : " << key << std::endl;
 	std::cout << "New Generated Key: " <<  newKey << std::endl;
 	std::cout << "Enc Vigenere Msg : " << encryptedMsg << std::endl;
 	std::cout << "Dec Vigenere Msg : " << decryptedMsg << std::endl;
 
    return 0;
}
