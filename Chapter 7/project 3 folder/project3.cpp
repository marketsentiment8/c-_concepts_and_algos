#include <iostream>

void delete_repeats(char array[], int &size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size;) {
            if (array[i] == array[j]) {
                for (int k = j; k < size - 1; ++k) {
                    array[k] = array[k + 1];
                }
                --size;
            } else {
                ++j;
            }
        }
    }
}

int main() {
    char a[10];
    int size;
    char choice;

    do {
        std::cout << "Enter the size of the array (up to 10): ";
        std::cin >> size;

        if (size < 1 || size > 10) {
            std::cout << "Invalid size. Please enter a size between 1 and 10." << std::endl;
            continue;
        }

        std::cout << "Enter the characters for the array: ";
        for (int i = 0; i < size; ++i) {
            std::cin >> a[i];
        }

        std::cout << "\nArray before deleting repeats: ";
        for (int i = 0; i < size; ++i) {
            std::cout << a[i] << " ";
        }

        delete_repeats(a, size);

        std::cout << "\nArray after deleting repeats: ";
        for (int i = 0; i < size; ++i) {
            std::cout << a[i] << " ";
        }
        std::cout << "\nNew size: " << size << std::endl;

        std::cout << "\nDo you want to test again? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y');

    return 0;
}
