#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    string WordFirst, WordSecond;
    int SizeMax = 0; int SizeMin = 0;
    InPut >> WordFirst >> WordSecond;
    SizeMax = (max(WordFirst.size(), WordSecond.size()));
    SizeMin = (min(WordFirst.size(), WordSecond.size()));
    int Difference = SizeMax - SizeMin;
    for(int i = 0; i < SizeMin; i++) {
        if(WordFirst[i] != WordSecond[i]) {
            Difference += 1;
        }
    }
    OutPut << Difference << endl;
}
