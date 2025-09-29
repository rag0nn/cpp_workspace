#pragma once
#include <string>
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

class EncryptionHelper {
    public:
        static std::string sha256(const std::string& input);
        static bool verifyPassword(const std::string& input, const std::string& storedHash);
};
