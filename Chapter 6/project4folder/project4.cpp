#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

double computeAverageWordLength(std::istream& input) {
    std::string word;
    int totalCharacters = 0;
    int wordCount = 0;

    while (input >> word) {
        int wordLength = 0;
        for (char ch : word) {
            if (std::isalpha(ch)) {
                ++wordLength;
            }
        }
        if (wordLength > 0) {
            totalCharacters += wordLength;
            ++wordCount;
        }
    }

    return wordCount > 0 ? static_cast<double>(totalCharacters) / wordCount : 0.0;
}

int main() {
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Unable to open file input.txt" << std::endl;
        return 1;
    }

    double averageWordLength = computeAverageWordLength(file);
    std::cout << "Average word length: " << averageWordLength << std::endl;

    file.close();
    return 0;
}
