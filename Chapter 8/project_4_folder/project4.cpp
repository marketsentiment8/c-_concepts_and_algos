#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, middleName, lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter middle name or initial (if none, press enter): ";
    cin.ignore();
    getline(cin, middleName);
    cout << "Enter last name: ";
    cin >> lastName;

    if (!middleName.empty() && middleName.back() != '.') {
        middleName += '.';
    }

    if (middleName.empty()) {
        cout << lastName << ", " << firstName << endl;
    } else {
        cout << lastName << ", " << firstName << " " << middleName << endl;
    }

    return 0;
}
