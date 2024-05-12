#include <iostream>
#include <string>
#include <cctype>

bool isLeapYear(int year) {
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}

int getCenturyValue(int year) {
    int century = year / 100;
    return (3 - (century % 4)) * 2;
}

int getYearValue(int year) {
    int lastTwoDigits = year % 100;
    return (lastTwoDigits / 4) + lastTwoDigits;
}

int getMonthValue(int month, int year) {
    bool leapYear = isLeapYear(year);
    switch (month) {
        case 1: // January
            return leapYear ? 6 : 0;
        case 2: // February
            return leapYear ? 2 : 3;
        case 3: // March
            return 3;
        case 4: // April
            return 6;
        case 5: // May
            return 1;
        case 6: // June
            return 4;
        case 7: // July
            return 6;
        case 8: // August
            return 2;
        case 9: // September
            return 5;
        case 10: // October
            return 0;
        case 11: // November
            return 3;
        case 12: // December
            return 5;
        default:
            return 0;
    }
}

void getInput(int& month, int& day, int& year) {
    std::string dateStr;
    std::cout << "Enter the date (MM/DD/YYYY or Month DD, YYYY): ";
    std::getline(std::cin, dateStr);


    size_t pos = dateStr.find_first_of("0123456789");
    if (pos != std::string::npos) {
        month = std::stoi(dateStr.substr(pos, 2));
        pos = dateStr.find_first_of("0123456789", pos + 2);
        day = std::stoi(dateStr.substr(pos, 2));
        pos = dateStr.find_first_of("0123456789", pos + 2);
        year = std::stoi(dateStr.substr(pos, 4));
    } else {
        std::cout << "Invalid date format.\n";
    }
}

int main() {
    int month, day, year;
    getInput(month, day, year);

    int dayOfWeek = (day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year)) % 7;

    std::string daysOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    std::cout << "The day of the week for " << month << "/" << day << "/" << year << " is " << daysOfWeek[dayOfWeek] << std::endl;

    return 0;
}
