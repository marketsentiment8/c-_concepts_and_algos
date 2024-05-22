#include <iostream>
#include <iomanip>

void getInput(int& currentHours, int& currentMinutes, int& waitHours, int& waitMinutes) {
    std::cout << "Enter the current time (hours and minutes): ";
    std::cin >> currentHours >> currentMinutes;
    std::cout << "Enter the waiting time (hours and minutes): ";
    std::cin >> waitHours >> waitMinutes;
}

void calculateNewTime(int currentHours, int currentMinutes, int waitHours, int waitMinutes, int& newHours, int& newMinutes) {
    newMinutes = (currentMinutes + waitMinutes) % 60;
    int extraHours = (currentMinutes + waitMinutes) / 60;
    newHours = (currentHours + waitHours + extraHours) % 24;
}

void convertTo12Hour(int hours, int& convHours, char& period) {
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

void displayNewTime12Hour(int newHours, int newMinutes) {
    int convHours;
    char period;
    convertTo12Hour(newHours, convHours, period);
    std::cout << "The new time is: " 
              << std::setw(2) << std::setfill('0') << convHours << ":" 
              << std::setw(2) << std::setfill('0') << newMinutes << " " 
              << period << "M" << std::endl;
}

int main() {
    int currentHours, currentMinutes, waitHours, waitMinutes;
    int newHours, newMinutes;
    char again;

    do {
        getInput(currentHours, currentMinutes, waitHours, waitMinutes);
        calculateNewTime(currentHours, currentMinutes, waitHours, waitMinutes, newHours, newMinutes);
        displayNewTime12Hour(newHours, newMinutes);

        std::cout << "Do you want to calculate another time? (y/n): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
