#include <iostream>

int main( ) {
    int numQuarter, numDime, numNickel;

    std::cout << "Enter the number of quarters: ";
    std::cin >> numQuarter;

    std::cout << "Enter the number of dimes: ";
    std::cin >> numDime;

    std::cout << "Enter the number of nickels: ";
    std::cin >> numNickel;

    int totalQuarter = numQuarter * 25;
    int totalDime = numDime * 10;
    int totalNickel = numNickel * 5;

    int total = totalQuarter + totalDime + totalNickel;

    std::cout << "You have a total of: " << total << std::endl;

}