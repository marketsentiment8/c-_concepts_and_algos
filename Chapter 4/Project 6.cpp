#include <iostream>
#include <unordered_map>
#include <iomanip>

const double TWINKIE_COST = 3.50;


double insertCoin();
void displayTotal(double total);

int main()
{
    double total = 0.00;

    while (total < TWINKIE_COST)
    {
        double coin = insertCoin();
        total += coin;

        displayTotal(total);
    }

    // Check if change is needed
    if (total > TWINKIE_COST)
    {
        double change = total - TWINKIE_COST;
        std::cout << "Enjoy your deep-fried twinkie! Change: $" << change << std::endl;
    }
    else
    {
        std::cout << "Enjoy your deep-fried twinkie!" << std::endl;
    }

    return 0;
}

double insertCoin()
{
    std::unordered_map<char, double> coinValues = {
        {'D', 1.00},
        {'q', 0.25},
        {'d', 0.10},
        {'n', 0.05},
        {'p', 0.01}
    };

    char coinType;
    std::cout << "Insert a coin (D for dollars, q for quarters, d for dimes, n for nickels, p for pennies): ";
    std::cin >> coinType;

    auto it = coinValues.find(coinType);
    if (it != coinValues.end())
    {
        return it->second;
    }
    else
    {
        std::cout << "Invalid coin. Please use D, q, d, n, or p." << std::endl;
        return 0; // Invalid coin, return 0 value
    }
}

void displayTotal(double total)
{
    std::cout << "Total amount: $" << std::setprecision(2) << total << std::endl;
}
