#include <iostream>
#include <cstring>

void extractInfo(const char* input, char* name, int& age, char* title) {
    char* inputCopy = new char[strlen(input) + 1];
    std::strcpy(inputCopy, input);

    char* token = std::strtok(inputCopy, " ");
    std::strcpy(name, token);

    token = std::strtok(nullptr, " ");
    age = std::atoi(token);

    token = std::strtok(nullptr, " ");
    std::strcpy(title, token);

    delete[] inputCopy;
}

int main() {
    const int MAX_LENGTH = 100;
    char input[MAX_LENGTH];

    std::cout << "Enter name, age, and title separated by space: ";
    std::cin.getline(input, MAX_LENGTH);

    char name[MAX_LENGTH];
    int age;
    char title[MAX_LENGTH];

    extractInfo(input, name, age, title);

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Title: " << title << std::endl;

    return 0;
}
