#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to generate random numbers for each digit from 0 to 9
void generateRandomNumbers(int randomNumbers[]) {
    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        randomNumbers[i] = (rand() % 3) + 1; // Random number between 1 and 3
    }
}

// Function to check if the response matches the PIN
bool authenticate(int pin, int randomNumbers[], int response) {
    int pinDigits[5];
    for (int i = 4; i >= 0; --i) {
        pinDigits[i] = pin % 10;
        pin /= 10;
    }

    for (int i = 4; i >= 0; --i) {
        if (randomNumbers[pinDigits[i]] != response % 10) {
            return false;
        }
        response /= 10;
    }

    return true;
}

int main() {
    int pin = 12345; // Actual PIN number
    int randomNumbers[10]; // Random numbers for each digit from 0 to 9

    generateRandomNumbers(randomNumbers);

    std::cout << "PIN: 0 1 2 3 4 5 6 7 8 9" << std::endl;
    std::cout << "NUM:";
    for (int i = 0; i < 10; ++i) {
        std::cout << " " << randomNumbers[i];
    }
    std::cout << std::endl;

    int response;
    std::cout << "Enter your response: ";
    std::cin >> response;

    if (authenticate(pin, randomNumbers, response)) {
        std::cout << "Authentication successful!" << std::endl;
    } else {
        std::cout << "Authentication failed." << std::endl;
    }

    return 0;
}
