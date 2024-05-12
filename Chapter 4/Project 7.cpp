#include <iostream>
#include <string>

int convertToMinutes(int hours, int minutes, const std::string& ampm) {
    int totalMinutes = hours % 12 * 60 + minutes;

    if (ampm == "PM" || ampm == "pm") {
        totalMinutes += 12 * 60;
    }

    return totalMinutes;
}

int computeDifference(int startHours, int startMinutes, const std::string& startAmpm, int futureHours, int futureMinutes, const std::string& futureAmpm) {
    int startTime = convertToMinutes(startHours, startMinutes, startAmpm);
    int futureTime = convertToMinutes(futureHours, futureMinutes, futureAmpm);

    int difference = futureTime - startTime;

    if (difference < 0) {
        difference += 24 * 60;
    }

    return difference;
}

int main() {
    int startHours, startMinutes, futureHours, futureMinutes;
    std::string startAmpm, futureAmpm;

    std::cout << "Enter start time (hours minutes AM/PM): ";
    std::cin >> startHours >> startMinutes >> startAmpm;

    std::cout << "Enter future time (hours minutes AM/PM, < 24 hours ahead): ";
    std::cin >> futureHours >> futureMinutes >> futureAmpm;

    int difference = computeDifference(startHours, startMinutes, startAmpm, futureHours, futureMinutes, futureAmpm);
    std::cout << "Time difference: " << difference << " minutes" << std::endl;

    return 0;
}
