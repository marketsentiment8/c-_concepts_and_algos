#include <iostream>

void printLargeC(char userChar) {
    std::cout << "   " << userChar << " " << userChar << " " << userChar << std::endl;
    std::cout << " " << userChar << "      " << userChar << std::endl;
    std::cout << userChar << std::endl;
    std::cout << userChar << std::endl;
    std::cout << userChar << std::endl;
    std::cout << userChar << std::endl;
    std::cout << userChar << std::endl;
    std::cout << " " << userChar << "      " << userChar << std::endl;
    std::cout << "   " << userChar << " " << userChar << " " << userChar << std::endl;
}

int main() {
    char userChar;

   
    std::cout << "Enter a character: ";
    std::cin >> userChar;

    printLargeC(userChar);

    return 0;
}
