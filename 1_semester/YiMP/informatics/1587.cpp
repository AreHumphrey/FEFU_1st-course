#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


using namespace std;

int main()
{
    int DlinaPosl, x, x1, RusultProg = 0;
    bool Flag = true, Srav = false;

    ifstream InPutFail("input.txt");
    ofstream OutPutFail("output.txt");

    InPutFail >> DlinaPosl;
    InPutFail>> x1;

    for (int i = 1; i < DlinaPosl; i++) {
        InPutFail >> x;
        if (x != x1) {
            if (Srav) {
                if (Flag) {
                    if (x > x1) {
                        Flag = false;
                    }
                    else {
                        RusultProg++;
                    }
                }
                else {
                    if (x < x1) {
                        Flag = true;
                    }
                    else {
                        RusultProg++;
                    }
                }
            }
            else {
                Flag = x < x1;
                Srav = true;
            }
        }
        else {
            RusultProg++;
        }
        x1 = x;
    }
    OutPutFail << RusultProg;
    return 0;
}