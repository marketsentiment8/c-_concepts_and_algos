#include <iostream>
using namespace std;

int main() {
    int max_people, number_people;

    cout << "Enter maximum number of people allowed at the event: ";
    cin >> max_people;

    cout << "Enter the number of people: ";
    cin >> number_people;

    if (number_people < max_people) {
        cout << "This event is legal. ";
        int remaining_capacity = max_people - number_people;
        cout << "You can invite " << remaining_capacity << " more people.";
    } else {
        cout << "This event cannot be held due to fire restrictions";
        int over_flow = number_people - max_people;
        cout << "There are " << over_flow << " people over the limit.";
    }

    return 0;
}
