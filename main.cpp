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

	// vigenere encoding

    std::string msg = "PHILIPPE123 AND I FEEL DAMN GREAT";
    std::string key = "HELLOHELMYLONGESTKEYFSKFSKLFKLSDKLFSDKFSFDSFSD";
    std::string encryptedMsg = encrypt_vigenere(msg, key);
    std::string newKey = extend_key(msg, key);
    std::string decryptedMsg = decrypt_vigenere(encryptedMsg, newKey);

 	std::cout << "Original Message: " << msg << std::endl;
 	std::cout << "Key: " << key << std::endl;
 	std::cout << "New Generated Key: " <<  newKey << std::endl;
 	std::cout << "Encrypted Message: " << encryptedMsg << std::endl;
 	std::cout << "Decrypted Message: " << decryptedMsg << std::endl;

 
    return 0;
}
