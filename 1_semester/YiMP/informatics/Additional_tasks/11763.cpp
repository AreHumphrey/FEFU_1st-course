#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    unsigned long long int A,B,Y,X;
    InPut >> A >> B;
    if(((A % 2 != 0) and (B % 2 == 0)) || (( A % 2 == 0) and (B % 2 != 0))){
        OutPut << -1;
    }
    else{
        Y = (((A - B) / 2) + B);
        X = A - Y;
        if((X < 0) || (Y < 0) || (X > Y)){
            OutPut << -1;
        }
        OutPut << X << " " << Y;
    }
}
