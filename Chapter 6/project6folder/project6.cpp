#include <iostream>
#include <fstream>
#include <string>
#include <regex>

void correctProgram(std::istream& inputFile, std::ostream& outputFile) {
    std::string line;
    std::regex cinIncorrect(R"(cin\s*<<)");
    std::regex coutIncorrect(R"(cout\s*>>)");
    std::regex cinCorrect(R"(cin\s*>>)");
    std::regex coutCorrect(R"(cout\s*<<)");

    while (std::getline(inputFile, line)) {
        line = std::regex_replace(line, cinIncorrect, "cin >>");
        line = std::regex_replace(line, coutIncorrect, "cout <<");
        line = std::regex_replace(line, cinCorrect, "cin >>");
        line = std::regex_replace(line, coutCorrect, "cout <<");
        outputFile << line << '\n';
    }
}

int main() {
    std::ifstream inputFile("input.cpp");
    if (!inputFile) {
        std::cerr << "Unable to open input file" << std::endl;
        return 1;
    }

    std::ofstream outputFile("output.cpp");
    if (!outputFile) {
        std::cerr << "Unable to open output file" << std::endl;
        return 1;
    }

    correctProgram(inputFile, outputFile);

    inputFile.close();
    outputFile.close();
    std::cout << "Program corrected and written to output.cpp" << std::endl;

    return 0;
}
