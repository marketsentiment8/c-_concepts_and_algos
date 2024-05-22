#include <iostream>

void compute_coins(int coin_value, int& num, int& amount_left) {
    num = amount_left / coin_value;
    amount_left %= coin_value;
}

int main() {
    char repeat;

    do {
        int amount;
        std::cout << "Enter the amount in cents (1 to 99): ";
        std::cin >> amount;

        if (amount < 1 || amount > 99) {
            std::cout << "Invalid input. Please enter a value between 1 and 99.\n";
            continue;
        }

        int quarters, dimes, pennies;
        int amount_left = amount;

        compute_coins(25, quarters, amount_left);
        compute_coins(10, dimes, amount_left);
        pennies = amount_left;

        std::cout << amount << " cents can be given as:\n";
        std::cout << quarters << " quarter(s) ";
        std::cout << dimes << " dime(s) ";
        std::cout << "and " << pennies << " penny(pennies)\n";

        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    std::cout << "see ya\n";

    return 0;
}
