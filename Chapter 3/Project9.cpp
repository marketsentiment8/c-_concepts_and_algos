 #include <iostream>
#include <random>

int main() {
    const int numSimulations = 10000;
    int winOriginal = 0;
    int winSwitch = 0;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> prizeDist(1, 3);

    for (int i = 0; i < numSimulations; i++) {
        int carBehind = prizeDist(rng);
        int initialChoice = prizeDist(rng);

        int doorRevealed;

        do {
            doorRevealed = prizeDist(rng);
        } while (doorRevealed == initialChoice || doorRevealed == carBehind);

        int newChoice;
        do {
            newChoice = prizeDist(rng);
        } while (newChoice == initialChoice || newChoice == doorRevealed);

        if (initialChoice == carBehind) {
            winOriginal++;
        }
        if (newChoice == carBehind) {
            winSwitch++;
        }
    }

    double probOriginal = static_cast<double>(winOriginal) / numSimulations;
    double probSwitch = static_cast<double>(winSwitch) / numSimulations;

    std::cout << "Probability of winning by sticking with the original choice: " << probOriginal << std::endl;
    std::cout << "Probability of winning by switching doors: " << probSwitch << std::endl;

    return 0;
}
