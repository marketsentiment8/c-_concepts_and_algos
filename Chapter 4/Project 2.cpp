#include <iostream>
#include <cmath>


double calculateHatSize(double weight, double height) {
    return (weight / height) * 2.9;
}


double calculateJacketSize(double weight, double height, int age) {
    double baseSize = (height * weight) / 288.0;
    int ageAdjustment = std::max(0, (age - 30) / 10); 
    return baseSize + (0.125 * ageAdjustment);
}


double calculateWaistSize(double weight, int age) {
    double baseSize = weight / 5.7;
    int ageAdjustment = std::max(0, (age - 28) / 2); 
    return baseSize + (0.1 * ageAdjustment);
}

int main() {
    char repeat;

    do {
        double weight, height;
        int age;

        
        std::cout << "Enter your weight in pounds: ";
        std::cin >> weight;
        std::cout << "Enter your height in inches: ";
        std::cin >> height;
        std::cout << "Enter your age: ";
        std::cin >> age;

       
        double hatSize = calculateHatSize(weight, height);
        double jacketSize = calculateJacketSize(weight, height, age);
        double waistSize = calculateWaistSize(weight, age);

        std::cout << "Hat size: " << hatSize << std::endl;
        std::cout << "Jacket size: " << jacketSize << " inches" << std::endl;
        std::cout << "Waist size: " << waistSize << " inches" << std::endl;

        
        std::cout << "Do you want to repeat the calculation? (y/n): ";
        std::cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
