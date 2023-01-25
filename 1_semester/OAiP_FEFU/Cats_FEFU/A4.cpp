#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
vector<int> ArrOfNumbers;
int A,B,C, NumbersRazriad;

int main(){
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    InPut>> A;
    NumbersRazriad = ceil(log10(A+1));
    for(int i = 0; i < NumbersRazriad; i++) {
        ArrOfNumbers.push_back(A%10);
        A /= 10;
    }
    for (int i = 0; i < NumbersRazriad; i++) {
        for (int j = 0; j < NumbersRazriad-1; j++) {
            if (ArrOfNumbers[j] > ArrOfNumbers[j + 1]) {
                int b = ArrOfNumbers[j];
                ArrOfNumbers[j] = ArrOfNumbers[j + 1];
                ArrOfNumbers[j + 1] = b;
            }
        }
    }
    for(int i = (NumbersRazriad-1); i >= 1; i--){
        B = (B*10) + ArrOfNumbers[i];
    }
    C = ArrOfNumbers[0];
    OutPut << B << endl << C ;
}
