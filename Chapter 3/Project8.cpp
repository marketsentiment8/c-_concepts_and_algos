#include <iostream>
#include <cmath>

int main() {
    char repeat;
    do {
        int n;
        double pi_approximation = 0.0;

        std::cout << "Enter the number of terms (n) to approximate pi: ";
        std::cin >> n;

        for (int i = 0; i < n; i++) {
            double term = 1.0 / (2 * i + 1);
            if (i % 2 == 1) {
                term = -term;
            }
            pi_approximation += term;
        }

        pi_approximation *= 4;

        std::cout << "Approximation of pi with " << n << " terms: " << pi_approximation << std::endl;

        std::cout << "Do you want to calculate again? (y/n): ";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
