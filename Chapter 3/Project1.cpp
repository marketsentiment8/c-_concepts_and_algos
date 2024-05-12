#include <iostream>
using namespace std;

int main() {
    char day[2];
    int startHour, startMinute, callLength;
    double cost;

    while (true) {
        cout << "Enter the day of the week (Mo, Tu, We, Th, Fr, Sa, Su): ";
        cin >> day;
        cout << "Enter the start time (24-hour notation, e.g., 13:30): ";
        cin >> startHour;
        cin.ignore(); 
        cin >> startMinute;
        cout << "Enter the length of the call in minutes: ";
        cin >> callLength;

        day[0] = tolower(day[0]);
        day[1] = tolower(day[1]);

        if ((day[0] == 'm' || day[0] == 't' || day[0] == 'w' || day[0] == 'h' || day[0] == 'f') &&
            (startHour >= 8 && startHour < 18)) {
            cost = 0.40 * callLength;
        } else if ((day[0] == 's' && day[1] == 'a') || (day[0] == 's' && day[1] == 'u')) {
            // Saturday and Sunday with rate 0.15
            cost = 0.15 * callLength;
        } else {
            cost = 0.25 * callLength;
        }

        cout << "The cost of the call is: $" << cost << endl;

        char choice;
        cout << "Do you want to calculate another call cost? (y/n): ";
        cin >> choice;

        if (tolower(choice) != 'y') {
            break; 
        }
    }

    return 0;
}
