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

void displayNewTime(int newHours, int newMinutes) {
    std::cout << "The new time is: " 
              << std::setw(2) << std::setfill('0') << newHours << ":" 
              << std::setw(2) << std::setfill('0') << newMinutes << std::endl;
}

int main() {
    int currentHours, currentMinutes, waitHours, waitMinutes;
    int newHours, newMinutes;
    char again;

    do {
        getInput(currentHours, currentMinutes, waitHours, waitMinutes);
        calculateNewTime(currentHours, currentMinutes, waitHours, waitMinutes, newHours, newMinutes);
        displayNewTime(newHours, newMinutes);

        std::cout << "Do you want to calculate another time? (y/n): ";
        std::cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}
