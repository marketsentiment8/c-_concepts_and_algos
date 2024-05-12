#include <iostream>
#include <algorithm>

using namespace std;

void sort(int [], char [], int);

int main() {
    const int SIZE = 26;
    char letters[SIZE] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
                          'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int occurrences[SIZE] = {0};

    // Read input line
    string input;
    getline(cin, input);

    // Count occurrences of each letter
    for (char c : input) {
        if (c >= 'a' && c <= 'z') {
            occurrences[c - 'a']++;
        }
    }

    // Sort letters and occurrences arrays
    sort(occurrences, letters, SIZE);

    // Output letter occurrences
    cout << "Letter : Number of Occurrences" << endl;
    for (int i = SIZE - 1; i >= 0; i--) {
        if (occurrences[i] > 0) {
            cout << letters[i] << " : " << occurrences[i] << endl;
        }
    }

    return 0;
}

// Modified sort function to sort arrays according to the values in the integer array
void sort(int arr[], char letters[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swap(letters[j], letters[j + 1]);
            }
        }
    }
}
