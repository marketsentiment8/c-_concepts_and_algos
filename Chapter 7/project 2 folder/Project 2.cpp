#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Function to convert a single hexadecimal digit to its decimal value
int hexToDecimal(char hex) {
    if (isdigit(hex))
        return hex - '0';
    else
        return toupper(hex) - 'A' + 10;
}

// Function to convert a hexadecimal numeral to its decimal equivalent
int hexToDecimalNum(char hex[], int len) {
    int decimalNum = 0;
    for (int i = 0; i < len; i++) {
        decimalNum = decimalNum * 16 + hexToDecimal(hex[i]);
    }
    return decimalNum;
}

// Function to add two hexadecimal numerals
void addHexNumerals(char hex1[], char hex2[], int len1, int len2) {
    int decimalNum1 = hexToDecimalNum(hex1, len1);
    int decimalNum2 = hexToDecimalNum(hex2, len2);
    unsigned long long decimalSum = decimalNum1 + decimalNum2;

    // Check if the result overflows 10 digits
    if (decimalSum > 0xFFFFFFFFFF) {
        cout << "Addition Overflow" << endl;
        return;
    }

    // Convert the decimal sum back to hexadecimal
    char hexSum[11];
    int index = 10;
    hexSum[index--] = '\0';  // Null terminator

    while (decimalSum > 0 && index >= 0) {
        int digit = decimalSum % 16;
        hexSum[index--] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
        decimalSum /= 16;
    }

    cout << "Sum: " << &hexSum[index + 1] << endl;
}

int main() {
    char hex1[11], hex2[11];
    int len1, len2;

    while (true) {
        cout << "Enter the first hexadecimal numeral (up to 10 digits): ";
        cin >> hex1;
        len1 = strlen(hex1);

        cout << "Enter the second hexadecimal numeral (up to 10 digits): ";
        cin >> hex2;
        len2 = strlen(hex2);

        addHexNumerals(hex1, hex2, len1, len2);

        char choice;
        cout << "Do you want to perform another addition? (y/n): ";
        cin >> choice;

        if (tolower(choice) == 'n')
            break;
    }

    return 0;
}
