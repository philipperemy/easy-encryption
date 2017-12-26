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

    std::string msg = "{\"HELLO\"THECRAZYPROGRAMMER;;";
    std::string key = "HELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLOHELLO";
    std::string encryptedMsg = encrypt_vigenere(msg, key);
    std::string newKey = extend_key(msg, key);
    std::string decryptedMsg = decrypt_vigenere(encryptedMsg, newKey);

 	std::cout << "Original Message: " << msg << std::endl;
 	std::cout << "Key: " << key << std::endl;
 	std::cout << "New Generated Key: " <<  newKey << std::endl;
 	std::cout << "Encrypted Message: " << encryptedMsg << std::endl;
 	std::cout << "Decrypted Message: " << decryptedMsg << std::endl;
 	
 	
 	// b64 encoding
 	
 	std::string msg2 = "hello the world";
 	std::string encoded64msg2 = base64_encode(msg2);
 	std::cout << encoded64msg2 << std::endl;
 	std::string decoded64msg2 = base64_decode(encoded64msg2);
 	std::cout << decoded64msg2 << std::endl;
 	
 	// vigenere and b64 encoding.
 	// works only for capital letters.
 	// https://www.thecrazyprogrammer.com/2017/08/vigenere-cipher-c-c.html
 	// https://stackoverflow.com/questions/342409/how-do-i-base64-encode-decode-in-c
 	std::string msg3 = "HELLO THE WORLD ITS PHILIPPE;;";
 	std::cout << "_________________________________________________" << std::endl;
 	std::cout << msg3 << std::endl;
 	msg3 = encrypt_vigenere(msg3, key);
 	std::cout << msg3 << std::endl;
 	msg3 = base64_encode(msg3);
 	std::cout << "Message to be sent: " << msg3 << std::endl;
 	msg3 = base64_decode(msg3);
 	std::cout << msg3 << std::endl;
 	std::cout << decrypt_vigenere(msg3, newKey) << std::endl; 	
 
    return 0;
}
