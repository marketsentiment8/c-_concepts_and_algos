#include <iostream>
#include <cmath>

double cal_for_bmr(int weight);
double cal_for_physAct(double intensity, int weight, int mins);
double cal_for_digestion(double totalCaloriesConsumed);

int main()
{
    int weight, mins;
    double intensity, totalCaloriesConsumed;

    std::cout << "Enter your weight in pounds: ";
    std::cin >> weight;

    double bmr = cal_for_bmr(weight);
    std::cout << "Basal Metabolic Rate (BMR) is: " << bmr << " calories/day" << std::endl;

    std::cout << "Enter the intensity of your workout (Walking 1mph: 1, Running 10mph: 17): ";
    std::cin >> intensity;

    std::cout << "Enter the number of minutes spent exercising: ";
    std::cin >> mins;

    double physActCalories = cal_for_physAct(intensity, weight, mins);
    std::cout << "Calories burned during physical activity: " << physActCalories << " calories/day" << std::endl;

    std::cout << "Enter the number of calories in one serving of your favorite food: ";
    std::cin >> totalCaloriesConsumed;

    double digestionCalories = cal_for_digestion(totalCaloriesConsumed);
    std::cout << "Calories required for digestion: " << digestionCalories << " calories/day" << std::endl;

    double totalCaloriesRequired = bmr + physActCalories + digestionCalories;
    int servingsPerDay = static_cast<int>(std::ceil(totalCaloriesRequired / totalCaloriesConsumed));


    std::cout << "To maintain your current weight at this activity level, you should eat approximately " << servingsPerDay << " servings of your favorite food per day." << std::endl;

    return 0;
}

double cal_for_bmr(int weight)
{
    return 70 * std::pow((weight / 2.2), 0.756);
}

double cal_for_physAct(double intensity, int weight, int mins)
{
    return 0.0385 * intensity * weight * mins;
}

double cal_for_digestion(double totalCaloriesConsumed)
{
    return totalCaloriesConsumed * 0.1;
}
