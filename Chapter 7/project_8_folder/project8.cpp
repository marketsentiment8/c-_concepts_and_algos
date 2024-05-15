#include <iostream>
#include <algorithm>
#include <string>

void sortArrays(char letters[], int occurrences[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (occurrences[i] < occurrences[j]) {
                std::swap(occurrences[i], occurrences[j]);
                std::swap(letters[i], letters[j]);
            }
        }
    }
}

void printOccurrences(char letters[], int occurrences[], int size) {
    std::cout << "Letter Number of Occurrences\n";
    for (int i = 0; i < size; ++i) {
        std::cout << letters[i] << " " << occurrences[i] << "\n";
    }
}

int main() {
    const int MAX_SIZE = 26; // assuming lowercase letters only
    char letters[MAX_SIZE] = {};
    int occurrences[MAX_SIZE] = {0};
    int size = 0;

    std::string input;
    std::cout << "Enter a line of text: ";
    std::getline(std::cin, input);

    // Count occurrences of each letter
    for (char c : input) {
        if (std::islower(c)) {
            int index = c - 'a';
            if (occurrences[index] == 0) {
                letters[size] = c;
                ++size;
            }
            ++occurrences[index];
        }
    }

    // Sort arrays
    sortArrays(letters, occurrences, size);

    // Print occurrences
    printOccurrences(letters, occurrences, size);

    return 0;
}
