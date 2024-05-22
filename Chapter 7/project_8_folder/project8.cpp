#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void sort(int counts[], char letters[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (counts[j] > counts[i]) {
                swap(counts[i], counts[j]);
                swap(letters[i], letters[j]);
            }
        }
    }
}

int main() {
    string input;
    cout << "Enter a line of text ending with a period: ";
    getline(cin, input);

    int counts[26] = {0};
    char letters[26];
    for (int i = 0; i < 26; i++) {
        letters[i] = 'a' + i;
    }

    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
        }
    }

    sort(counts, letters, 26);

    cout << "Letter Number of Occurrences" << endl;
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            cout << letters[i] << " " << counts[i] << endl;
        }
    }

    return 0;
}
