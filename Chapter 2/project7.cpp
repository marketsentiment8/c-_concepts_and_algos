#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double inflation_rate, inflation_percent, final_cost, cost;
    int num_years;

    cout << "Enter the item's inflation rate: ";
    cin >> inflation_percent;

    inflation_rate = inflation_percent / 100;
    cout << "Enter the number of years: ";
    cin >> num_years;

    cout << "Enter the initial cost of the item: ";
    cin >> cost;

    final_cost = cost * inflation_rate * num_years;
    final_cost = cost + final_cost;

    // Set precision to two decimal places
    cout << fixed << setprecision(2);

    cout << "After " << num_years << " years, the cost will be: $" << final_cost << std::endl;

    return 0;
}
