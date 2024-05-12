#include <iostream>

int main() {
    int N;
    std::cout << "How many exercises to input? ";
    std::cin >> N;

    double totalPointsEarned = 0.0;
    double totalPointsPossible = 0.0;

    for (int i = 1; i <= N; i++) {
        double scoreReceived, totalPoints;
        std::cout << "Score received for exercise " << i << ": ";
        std::cin >> scoreReceived;
        std::cout << "Total points possible for exercise " << i << ": ";
        std::cin >> totalPoints;

        totalPointsEarned += scoreReceived;
        totalPointsPossible += totalPoints;
    }

    double percentage = (totalPointsEarned / totalPointsPossible) * 100.0;

    std::cout << "Your total is " << totalPointsEarned << " out of " << totalPointsPossible << ", or " << percentage << "%" << std::endl;
 
    return 0;
}
