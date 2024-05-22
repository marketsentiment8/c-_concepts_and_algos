#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int pin[5] = {1, 2, 3, 4, 5};
    int randomNumbers[10];

    cout << "PIN: ";
    for (int i = 0; i < 10; i++) {
        randomNumbers[i] = rand() % 3 + 1;
        cout << i << " ";
    }
    cout << endl;

    cout << "NUM: ";
    for (int i = 0; i < 10; i++) {
        cout << randomNumbers[i] << " ";
    }
    cout << endl;

    cout << "Enter the response: ";
    string response;
    cin >> response;

    bool correct = true;
    for (int i = 0; i < 5; i++) {
        if (response[i] - '0' != randomNumbers[pin[i]]) {
            correct = false;
            break;
        }
    }

    if (correct) {
        cout << "Authenticated successfully!" << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }

    return 0;
}
