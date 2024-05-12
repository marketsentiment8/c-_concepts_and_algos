#include <iostream>

int main( ){
    std::string gender;
    int height;
    int weight;
    int chocobar_cal; 
    int age;
    double BMR;

    chocobar_cal = 230;

    std::cout<< "Enter your gender(M/F): ";
    std::cin>> gender;

    std::cout<< "Enter your height: ";
    std::cin>> height;

    std::cout<< "Enter weight: ";
    std::cin>> weight;

    std::cout<< "Enter your age: ";
    std::cin >> age;

    if (gender == "M" ){
        BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    } else {
        BMR = 655 + (4.3 * weight) + (4.7 * height) - (4.7 * age);
    }
    std::cout << "You need to eat " << BMR / chocobar_cal << " Chocolate bars to keep your weight";
}