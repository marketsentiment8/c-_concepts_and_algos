#include <iostream>
#include <iomanip>

void getInput(int& hours, int& minutes) {
    std::cout << "Enter hours (0-23): ";
    std::cin >> hours;
    std::cout << "Enter minutes (0-59): ";
    std::cin >> minutes;
}

void convertTo12Hour(int hours, int minutes, int& convHours, char& period) {
    if (hours == 0) {
        convHours = 12;
        period = 'A';
    } else if (hours == 12) {
        convHours = 12;
        period = 'P';
    } else if (hours < 12) {
        convHours = hours;
        period = 'A';
    } else {
        convHours = hours - 12;
        period = 'P';
    }
}

void display12HourTime(int hours, int minutes, char period) {
    std::cout << "The time in 12-hour notation is: " 
              << std::setw(2) << std::setfill('0') << hours << ":" 
              << std::setw(2) << std::setfill('0') << minutes << " " 
              << period << "M" << std::endl;
}

int main() {
    int hours, minutes, convHours;
    char period;
    char again;

    do {
        getInput(hours, minutes);
        convertTo12Hour(hours, minutes, convHours, period);
        display12HourTime(convHours, minutes, period);

        std::cout << "Do you want to convert another time? (y/n): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
