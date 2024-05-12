#include <iostream>

bool containsInvalidDigits(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit == 1 || digit == 4 || digit == 7) {
            return true;
        }
        num /= 10;
    }
    return false;
}

void findValidTemperatures(int temp, int &smaller, int &larger) {
    smaller = temp;
    larger = temp;

    while (containsInvalidDigits(smaller) || smaller < 0) {
        smaller--;
    }

    while (containsInvalidDigits(larger) || larger > 999) {
        larger++;
    }
}

int main() {
    int desiredTemperature;

    std::cout << "Enter the desired temperature (0-999 degrees): ";
    std::cin >> desiredTemperature;

    if (desiredTemperature >= 0 && desiredTemperature <= 999) {
        int smaller, larger;
        findValidTemperatures(desiredTemperature, smaller, larger);
        std::cout << "The next smallest valid temperature is " << smaller << std::endl;
        std::cout << "The next largest valid temperature is " << larger << std::endl;
    }
    else {
        std::cout << "Invalid input. Temperature must be between 0 and 999." << std::endl;
    }

    return 0;
}
