#include <iostream>
#include <string>
using namespace std;

string decryptMessage(const string &encryptedMessage, int key) {
    string decryptedMessage;
    for (char c : encryptedMessage) {
        int decryptedChar = (c - key < 32) ? (127 - (32 - (c - key))) : (c - key);
        decryptedMessage += static_cast<char>(decryptedChar);
    }
    return decryptedMessage;
}

int main() {
    string encryptedMessage = ":mmZ\\dxZmx]Zpgy";
    for (int key = 1; key <= 100; key++) {
        string decryptedMessage = decryptMessage(encryptedMessage, key);
        cout << "Key " << key << ": " << decryptedMessage << endl;
    }
    return 0;
}
