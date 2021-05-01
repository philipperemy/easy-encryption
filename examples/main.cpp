#include <iostream>
#include "../src/EasyEncryption.h"

using namespace easy::encryption;

int main() {
 	std::string msg = "{\"id\":1,\"method\":\"service.subscribe\",\"params\":[\"myapp/0.1c\", null,\"0.0.0.0\",\"80\"]}";
 	std::string key = "THISISMYKEY";

 	std::cout << "  message to send: " << msg << std::endl;
 	std::string encrypted_msg = EasyEncryption::encrypt(msg, key);
 	std::cout << "encrypted message: " << encrypted_msg << std::endl;
 	std::string decrypted_msg = EasyEncryption::decrypt(encrypted_msg, key);
 	std::cout << "decrypted message: " << decrypted_msg << std::endl;

    return 0;
}
