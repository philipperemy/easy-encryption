#include "Base64.h"

using namespace easy::encryption;

std::string Base64::encode(const std::string &in) {
    unsigned long long int inStringLen = in.size();
    int valA = 0, valB = -6;
    std::string out;

    for (int i = 0; i < inStringLen; i++) {
        valA = (valA << 8) + in[i];
        valB += 8;

        while (valB >= 0) {
            out.push_back(BASE64_AVAILABLE_CHARS[(valA >> valB) & 0x3F]);
            valB -= 6;
        }
    }

    if (valB > -6)
        out.push_back(BASE64_AVAILABLE_CHARS[((valA << 8) >> (valB + 8)) & 0x3F]);

    while (out.size() % 4)
        out.push_back(0x3D);

    return out;
}

std::string Base64::decode(const std::string &in) {
    unsigned long long int inStringLen = in.size();
    std::vector<int> T(256, -1);
    std::string out;

    int i;
    for (i = 0; i < BASE64_AVAILABLE_CHARS_SIZE; i++)
        T[BASE64_AVAILABLE_CHARS[i]] = i;

    int valA = 0, valB = -8;
    for (i = 0; i < inStringLen; i++) {
        if (T[in[i]] == -1)
            break;

        valA = (valA << 6) + T[in[i]];
        valB += 6;

        if (valB >= 0) {
            out.push_back(char((valA >> valB) & 0xFF));
            valB -= 8;
        }
    }

    return out;
}
