#include <iostream>
#include <string>
using namespace std;

bool isInteger(const string &word) {
    for (char c : word) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

string replaceDigitsWithX(const string &sentence) {
    string result;
    string word;
    for (char c : sentence) {
        if (isalnum(c)) {
            word += c;
        } else {
            if (isInteger(word)) {
                for (char &wc : word) {
                    wc = 'x';
                }
            }
            result += word + c;
            word.clear();
        }
    }
    if (isInteger(word)) {
        for (char &wc : word) {
            wc = 'x';
        }
    }
    result += word;
    return result;
}

int main() {
    string sentence;
    char choice;
    do {
        cout << "Enter a line of text: ";
        getline(cin, sentence);

        string updatedSentence = replaceDigitsWithX(sentence);
        cout << updatedSentence << endl;

        cout << "Do you want to enter another line? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
