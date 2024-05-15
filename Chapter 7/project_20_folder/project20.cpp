#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

const int MAX_AGE = 120;

// Function to read death probabilities from file into arrays
void readDeathProbabilities(double maleProbabilities[], double femaleProbabilities[]) {
    std::ifstream file("LifeDeathProbability.txt");
    if (!file) {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(1);
    }

    int age;
    double maleProb, femaleProb;
    while (file >> age >> maleProb >> femaleProb) {
        maleProbabilities[age] = maleProb;
        femaleProbabilities[age] = femaleProb;
    }

    file.close();
}

// Function to simulate life expectancy
int simulateLifeExpectancy(double probabilities[], int age) {
    srand(time(0));
    while (age < MAX_AGE) {
        double random = static_cast<double>(rand()) / RAND_MAX; // Generate random number between 0 and 1
        if (random <= probabilities[age]) {
            return age;
        }
        age++;
    }
    return MAX_AGE; // If age reaches 120, predict the user will live to 120
}

int main() {
    double maleProbabilities[MAX_AGE + 1] = {0}; // Initialize arrays with size 121
    double femaleProbabilities[MAX_AGE + 1] = {0};

    readDeathProbabilities(maleProbabilities, femaleProbabilities);

    char sex;
    int age;

    std::cout << "Enter your sex (M/F): ";
    std::cin >> sex;

    if (sex != 'M' && sex != 'F') {
        std::cerr << "Error: Invalid sex entered." << std::endl;
        return 1;
    }

    std::cout << "Enter your age: ";
    std::cin >> age;

    if (age < 0 || age > MAX_AGE) {
        std::cerr << "Error: Invalid age entered." << std::endl;
        return 1;
    }

    double* probabilities = (sex == 'M') ? maleProbabilities : femaleProbabilities;

    int predictedAge = simulateLifeExpectancy(probabilities, age);
    std::cout << "You are predicted to live until age " << predictedAge << "." << std::endl;

    return 0;
}
