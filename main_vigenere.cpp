#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "vigenere.h"
#include "b64.h"

using namespace std;

int main() {

	// Vigenere encoding

    std::string msg = "HELLO WORLD";
    std::string key = "THISISALONGPRIVATEKEY";
    std::string encryptedMsg = encrypt_vigenere(msg, key);
    std::string newKey = extend_key(msg, key);
    std::string decryptedMsg = decrypt_vigenere(encryptedMsg, newKey);

 	std::cout << "Original Message : " << msg << std::endl;
 	std::cout << "Key              : " << key << std::endl;
 	std::cout << "New Generated Key: " <<  newKey << std::endl;
 	std::cout << "Enc Vigenere Msg : " << encryptedMsg << std::endl;
 	std::cout << "Dec Vigenere Msg : " << decryptedMsg << std::endl;
 
    return 0;
}
