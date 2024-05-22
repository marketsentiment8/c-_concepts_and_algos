#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct LifeData {
    int age;
    double maleProb;
    double femaleProb;
};

int main() {
    ifstream file("LifeDeathProbability.txt");
    if (!file) {
        cout << "File could not be opened." << endl;
        return 1;
    }

    vector<LifeData> data;
    LifeData temp;
    while (file >> temp.age >> temp.maleProb >> temp.femaleProb) {
        data.push_back(temp);
    }
    file.close();

    char sex;
    int age;
    cout << "Enter your sex (M/F): ";
    cin >> sex;
    cout << "Enter your current age: ";
    cin >> age;

    srand(time(0));
    while (age < 120) {
        double prob = (sex == 'M' || sex == 'm') ? data[age].maleProb : data[age].femaleProb;
        double randomValue = static_cast<double>(rand()) / RAND_MAX;
        if (randomValue <= prob) {
            cout << "You will live to age: " << age << endl;
            return 0;
        }
        age++;
    }
    cout << "You will live to age: 120" << endl;

    return 0;
}
