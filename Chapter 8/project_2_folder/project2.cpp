#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <sstream>
using namespace std;

int main() {
    string line;
    cout << "Enter a line of text: ";
    getline(cin, line);

    map<char, int> letterCount;
    int wordCount = 0;

    // Convert to lowercase and count letters
    for (char &c : line) {
        if (isalpha(c)) {
            c = tolower(c);
            letterCount[c]++;
        }
    }

    // Count words
    stringstream ss(line);
    string word;
    while (ss >> word) {
        wordCount++;
    }

    cout << wordCount << " words" << endl;
    for (const auto &entry : letterCount) {
        cout << entry.first << " " << entry.second << endl;
    }

    return 0;
}
