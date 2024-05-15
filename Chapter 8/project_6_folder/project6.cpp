#include <iostream>
#include <string>
#include <cctype>

// Function to replace masculine pronouns with gender-neutral pronouns
std::string replacePronouns(const std::string& sentence) {
    std::string result;

    // Iterate through the sentence character by character
    for (size_t i = 0; i < sentence.length(); ++i) {
        // Check for the start of a word
        if (std::isalpha(sentence[i])) {
            size_t start = i;
            // Find the end of the word
            while (i < sentence.length() && std::isalpha(sentence[i])) {
                ++i;
            }
            size_t end = i;

            // Extract the word
            std::string word = sentence.substr(start, end - start);

            // Replace masculine pronouns
            if (word == "he" || word == "He") {
                result += "she or he";
            } else if (word == "his" || word == "His") {
                result += "her(s)";
            } else {
                result += word;
            }
        } else {
            // Preserve non-alphabetic characters
            result += sentence[i];
        }
    }

    return result;
}

int main() {
    char repeat;
    do {
        std::string sentence;

        std::cout << "Enter a sentence: ";
        std::getline(std::cin, sentence);

        std::string modifiedSentence = replacePronouns(sentence);

        std::cout << "Suggested changed version: " << modifiedSentence << std::endl;

        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> repeat;
        std::cin.ignore(); // Ignore newline character

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
