#include <iostream>

int main() {
    int num;
    int positiveSum = 0;
    int negativeOrZeroSum = 0;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Enter a whole number: ";
        std::cin >> num;

        
        if (num > 0) {
            positiveSum += num;
        } else {
            negativeOrZeroSum += num;
        }
    }

    int totalSum = positiveSum + negativeOrZeroSum;

  
    std::cout << "Sum of positive numbers: " << positiveSum << std::endl;
    std::cout << "Sum of negative numbers or zero: " << negativeOrZeroSum << std::endl;
    std::cout << "Sum of all numbers: " << totalSum << std::endl;

    return 0;
}
