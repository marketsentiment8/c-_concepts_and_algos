#include <iostream>

void getInput(int& hours, int& mins, int& waitHours, int& waitMins);
void getWaitTime(int& hours, int& mins, int& waitHours, int& waitMins);

int main() {
    char choice;

    do {
        int hours, mins, waitHours, waitMins;

        getInput(hours, mins, waitHours, waitMins);
        getWaitTime(hours, mins, waitHours, waitMins);

      
        std::string period = (hours < 12) ? "AM" : "PM";

     
        if (hours > 12) {
            hours -= 12;
        }

        std::cout << "The new time after waiting will be: " << hours << ":" << mins << " " << period << std::endl;

        std::cout << "Do you want to calculate another time after waiting? (Y/N): ";
        std::cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    std::cout << "Program ended" << std::endl;

    return 0;
}

void getInput(int& hours, int& mins, int& waitHours, int& waitMins) {
    std::cout << "Enter the time in 12-hour notation (HH MM AM/PM): ";
    std::cin >> hours >> mins;

    
    std::string period;
    std::cin >> period;

    if (period == "PM" || period == "pm") {
        hours += 12;
    }

    std::cout << "Enter the wait time in 12-hour notation (HH MM): ";
    std::cin >> waitHours >> waitMins;
}

void getWaitTime(int& hours, int& mins, int& waitHours, int& waitMins) {
    
    hours = (hours + waitHours + (mins + waitMins) / 60) % 24;

    
    mins = (mins + waitMins) % 60;
}
