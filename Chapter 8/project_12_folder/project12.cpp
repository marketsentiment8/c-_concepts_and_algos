#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

// Function to convert time to military time
std::string convertToMilitaryTime(const std::string& timeStr) {
    std::stringstream ss(timeStr);
    std::string hourStr, minuteStr, ampm;
    char colon, space;

    ss >> hourStr >> colon >> minuteStr >> ampm;

    int hour = std::stoi(hourStr);
    int minute = std::stoi(minuteStr);

    // Adjust hour for PM time
    if (ampm == "PM" && hour < 12) {
        hour += 12;
    }

    // Adjust hour for AM time at 12 AM
    if (ampm == "AM" && hour == 12) {
        hour = 0;
    }

    // Convert hour and minute to 4-digit military time
    std::ostringstream militaryTime;
    militaryTime << std::setw(2) << std::setfill('0') << hour << std::setw(2) << minute << " hours";

    return militaryTime.str();
}

int main() {
    std::string inputTime;

    std::cout << "Enter the time (HH:MM AM/PM): ";
    std::getline(std::cin, inputTime);

    std::string militaryTime = convertToMilitaryTime(inputTime);

    std::cout << "Military time: " << militaryTime << std::endl;

    return 0;
}
