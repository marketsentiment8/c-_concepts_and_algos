#include <iostream>

int main() {
    int num1, num2;

    
    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    std::cout << "Enter the second integer: ";
    std::cin >> num2;

    
    int sum = num1 + num2;
    int product = num1 * num2;

    
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    return 0;
}
