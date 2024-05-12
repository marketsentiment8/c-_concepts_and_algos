#include <iostream>

// Function prototypes
void getInput(int& hours, int& minutes);
void convertTo12Hour(int& hours, char& period);
void displayOutput(int hours, int minutes, char period);

int main() {
    char choice;

    do {
        int hours, minutes;
        char period;

        // Get user input
        getInput(hours, minutes);

        // Convert to 12-hour notation
        convertTo12Hour(hours, period);

        // Display the output
        displayOutput(hours, minutes, period);

        // Ask the user if they want to continue
        std::cout << "Do you want to convert another time? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    std::cout << "Program ended" << std::endl;

    return 0;
}

// Function to get input from the user
void getInput(int& hours, int& minutes) {
    std::cout << "Enter the time in 24-hour notation (HH MM): ";
    std::cin >> hours >> minutes;
}

// Function to convert 24-hour notation to 12-hour notation
void convertTo12Hour(int& hours, char& period) {
    if (hours >= 0 && hours <= 11) {
        period = 'A';
        if (hours == 0) {
            hours = 12;
        }
    } else {
        period = 'P';
        if (hours > 12) {
            hours -= 12;
        }
    }
}

// Function to display the converted time
void displayOutput(int hours, int minutes, char period) {
    std::cout << "Converted time: " << hours << ":";

    // Ensure minutes are displayed with a leading zero if necessary
    if (minutes < 10) {
        std::cout << "0";
    }

    std::cout << minutes << " " << ((period == 'A') ? "AM" : "PM") << std::endl;
}
