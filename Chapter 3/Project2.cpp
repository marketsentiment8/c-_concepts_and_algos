#include <iostream>
#include <cmath>

int main() {
    while (true) {
        double a, b, c;

     
        std::cout << "Enter coefficients for a quadratic equation (a, b, c): ";
        std::cin >> a >> b >> c;

       
        if (a == 0) {
            std::cout << "Error: 'a' cannot be zero. Please enter valid coefficients." << std::endl;
            continue;
        }

       
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
        
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            std::cout << "Two real roots: " << root1 << " and " << root2 << std::endl;
        } else if (discriminant == 0) {
            
            double root = -b / (2 * a);
            std::cout << "Single real root: " << root << std::endl;
        } else {
            
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);
            std::cout << "Two complex roots: " << realPart << " + " << imaginaryPart << "i and " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }

        
        char choice;
        std::cout << "Do you want to solve another equation? (Y/N): ";
        std::cin >> choice;
        if (choice != 'Y' && choice != 'y') {
            break;
        }
    }

    return 0;
}
