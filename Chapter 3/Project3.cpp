#include <iostream>

std::string arabicToRoman(int year) {
    const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const std::string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    std::string result = "";

    for (int i = 0; i < 13; i++) {
        while (year >= values[i]) {
            result += numerals[i];
            year -= values[i];
        }
    }

    return result;
}

int main() {
    while (true) {
        int year;

        // Input year
        std::cout << "Enter a year (between 1000 and 3000): ";
        std::cin >> year;

        if (year < 1000 || year > 3000) {
            std::cout << "Year must be between 1000 and 3000. Please enter a valid year." << std::endl;
            continue;
        }

        std::string roman = arabicToRoman(year);

        std::cout << "Roman numeral representation: " << roman << std::endl;

        char choice;
        std::cout << "Do you want to convert another year? (Y/N): ";
        std::cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }

    return 0;
}
