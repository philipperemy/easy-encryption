#pragma once

#include <string>
#include <vector>
#include <chrono>

constexpr int BASE64_AVAILABLE_CHARS_SIZE = 65;
constexpr char BASE64_AVAILABLE_CHARS[BASE64_AVAILABLE_CHARS_SIZE] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789+/";

constexpr int VIGENERE_AVAILABLE_CHARS_SIZE = 63;
constexpr char VIGENERE_AVAILABLE_CHARS[VIGENERE_AVAILABLE_CHARS_SIZE] = "0123456789AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
