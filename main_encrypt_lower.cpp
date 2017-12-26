#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include "encrypt.h"

using namespace std;

std::string to_upper(std::string msg) {
	std::string output = msg;
	std::locale loc;
	for (std::string::size_type i=0; i<msg.length(); ++i) {
	    output[i] = std::toupper(msg[i],loc);
	}
	return output;
}

std::string to_lower(std::string msg) {
	std::string output = msg;
	std::locale loc;
	for (std::string::size_type i=0; i<msg.length(); ++i) {
	    output[i] = std::tolower(msg[i],loc);
	}
	return output;
}

int main() {
 	std::string msg = "{\"id\":1,\"method\":\"service.subscribe\",\"params\":[\"myapp/0.1c\", null,\"0.0.0.0\",\"80\"]}";
 	std::cout << msg << std::endl;
 	std::string upper_msg = to_upper(msg);
 	std::cout << upper_msg << std::endl;
 	std::string key = "THISISMYKEY";
 	std::cout << "  message to send: " << upper_msg << std::endl;
 	std::string encrypted_msg = encrypt(upper_msg, key);
 	std::cout << "encrypted message: " << encrypted_msg << std::endl;
 	std::string decrypted_msg = decrypt(encrypted_msg, key);
 	std::cout << "decrypted message: " << to_lower(decrypted_msg) << std::endl;
 	
    return 0;
}
