#include <iostream>
#include "../src/base64//Base64.h"

using namespace easy::encryption;

int main() {
    // Base64 encoding
    std::string msg = "HELLO WORLD";

    std::string encodedMsg = Base64::encode(msg);
    std::string decodedMsg = Base64::decode(encodedMsg);

    std::cout << "Original Message : " << msg << std::endl;
    std::cout << "Enc Base64 Msg : " << encodedMsg << std::endl;
    std::cout << "Dec Base64 Msg : " << decodedMsg << std::endl;

    return 0;
}
