#include <iostream>
#include <fstream>





void junkmail()



int main(){

    using namespace std;

    ifstream in_stream;
    ofstream out_stream;

    in_stream.open("infile.txt");
    out_stream.open("outfile.txt");

    string input_name;

    cout << "Enter a name" << input_name;

    return 0;

}
