#include <iostream>
#include <fstream>
#include <string>

int countWordsInFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return -1;
    }

    std::string word;
    int wordCount = 0;

    while (file >> word) {
        ++wordCount;
    }

    file.close();
    return wordCount;
}

int main() {
    std::string filename;
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;

    int wordCount = countWordsInFile(filename);
    if (wordCount >= 0) {
        std::cout << "The file " << filename << " contains " << wordCount << " words." << std::endl;
    }

    return 0;
}
