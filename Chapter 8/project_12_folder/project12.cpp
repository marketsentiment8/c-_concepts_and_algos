#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

string convertToMilitaryTime(const string &timeStr) {
    stringstream ss(timeStr);
    int hour, minute;
    char colon;
    string period;

    // Read and parse the time string
    ss >> hour >> colon >> minute >> period;

    // Check for any parsing errors
    if (ss.fail() || colon != ':' || (period != "AM" && period != "PM")) {
        throw invalid_argument("Invalid time format.");
    }

    // Validate the hour and minute ranges
    if (hour < 1 || hour > 12 || minute < 0 || minute > 59) {
        throw out_of_range("Invalid time value.");
    }

    // Convert to 24-hour format
    if (period == "PM" && hour != 12) {
        hour += 12;
    } else if (period == "AM" && hour == 12) {
        hour = 0;
    }

    // Format the output as HHMM
    stringstream result;
    result << setw(2) << setfill('0') << hour << setw(2) << setfill('0') << minute << " hours";

    return result.str();
}

int main() {
    string timeStr;
    cout << "Enter the time (HH:MM AM/PM): ";
    getline(cin, timeStr);

    try {
        string militaryTime = convertToMilitaryTime(timeStr);
        cout << "Military Time: " << militaryTime << endl;
    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
    } catch (const out_of_range &e) {
        cerr << e.what() << endl;
    }

    return 0;
}
