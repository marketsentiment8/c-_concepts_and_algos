#include <iostream>
#include <string>

// Function to decrypt the intercepted message
std::string decryptMessage(const std::string& message, int key) {
    std::string decryptedMessage;

    for (char c : message) {
        int decryptedChar = c - key;
        if (decryptedChar < 32) {
            decryptedChar = 127 - (32 - decryptedChar);
        }
        decryptedMessage += static_cast<char>(decryptedChar);
    }

    return decryptedMessage;
}

// Function to check if the decrypted message contains only visible ASCII characters
bool isValidMessage(const std::string& message) {
    for (char c : message) {
        if (c < 32 || c > 126) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string interceptedMessage = ":mmZ\\dxZmx]Zpgy";

    std::cout << "Intercepted message: " << interceptedMessage << std::endl;
    std::cout << "Decrypted messages with possible keys:" << std::endl;

    // Try decoding the intercepted message with keys from 1 to 100
    for (int key = 1; key <= 100; ++key) {
        std::string decrypted = decryptMessage(interceptedMessage, key);
        if (isValidMessage(decrypted)) {
            std::cout << "Key " << key << ": " << decrypted << std::endl;
        }
    }

    return 0;
}
