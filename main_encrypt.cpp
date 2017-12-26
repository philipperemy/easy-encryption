#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"

using namespace std;

int main() {
 	std::string msg = "HELLO WORLD";
 	std::string key = "THISISMYKEY";
 	std::cout << "  message to send: " << msg << std::endl;
 	std::string encrypted_msg = encrypt(msg, key);
 	std::cout << "encrypted message: " << encrypted_msg << std::endl;
 	std::string decrypted_msg = decrypt(encrypted_msg, key);
 	std::cout << "decrypted message: " << decrypted_msg << std::endl;
    return 0;
}
