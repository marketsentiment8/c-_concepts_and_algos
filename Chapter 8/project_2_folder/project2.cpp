#include <iostream>
#include <string>

void extractInfo(const std::string& input, std::string& name, int& age, std::string& title) {
    size_t pos = input.find(' ');
    name = input.substr(0, pos);
    
    size_t nextPos = input.find(' ', pos + 1);
    age = std::stoi(input.substr(pos + 1, nextPos - pos - 1));
    
    title = input.substr(nextPos + 1);
}

int main() {
    std::string input;
    
    std::cout << "Enter name, age, and title separated by space: ";
    std::getline(std::cin, input);

    std::string name, title;
    int age;

    extractInfo(input, name, age, title);

    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Title: " << title << std::endl;

    return 0;
}
