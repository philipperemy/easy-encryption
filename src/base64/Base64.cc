#include "Base64.h"

using namespace easy::encryption::base64;

std::string Base64::encode(const std::string &in) {
    std::string out;
    int valA = 0, valB = -6;

    for (char c : in) {
        valA = (valA << 8) + c;
        valB += 8;

        while (valB >= 0) {
            out.push_back(BASE64_AVAILABLE_CHARS[(valA >> valB) & 0x3F]);
            valB -= 6;
        }
    }

    if (valB > -6)
        out.push_back(BASE64_AVAILABLE_CHARS[((valA << 8) >> (valB + 8)) & 0x3F]);

    while (out.size() % 4)
        out.push_back('=');

    return out;
}

std::string Base64::decode(const std::string &in) {
    std::string out;
    std::vector<int> T(256, -1);

    for (int i = 0; i < BASE64_AVAILABLE_CHARS_SIZE; i++)
        T[BASE64_AVAILABLE_CHARS[i]] = i;

    int valA = 0, valB = -8;
    for (char c : in) {
        if (T[c] == -1)
            break;

        valA = (valA << 6) + T[c];
        valB += 6;

        if (valB >= 0) {
            out.push_back(char((valA >> valB) & 0xFF));
            valB -= 8;
        }
    }

    return out;
}
