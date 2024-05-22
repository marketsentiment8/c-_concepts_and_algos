#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string correctSentence(const string &sentence) {
    string result;
    bool newWord = true;
    bool inWhitespace = false;

    for (char c : sentence) {
        if (isspace(c)) {
            if (!inWhitespace) {
                result += ' ';
                inWhitespace = true;
            }
        } else {
            if (newWord) {
                result += toupper(c);
                newWord = false;
            } else {
                result += tolower(c);
            }
            inWhitespace = false;
        }
    }
    if (result.back() == ' ') {
        result.pop_back();
    }
    return result;
}

int main() {
    string sentence;
    cout << "Enter a sentence (up to 100 characters) ending with a period: ";
    getline(cin, sentence);

    if (sentence.back() != '.') {
        sentence += '.';
    }

    string correctedSentence = correctSentence(sentence);
    cout << correctedSentence << endl;

    return 0;
}
