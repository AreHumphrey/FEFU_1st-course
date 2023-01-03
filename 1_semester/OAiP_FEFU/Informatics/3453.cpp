#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <set>

using namespace std;

int main()
{
    string st;
    int N;
    int Element;
    set<int> ArrMass = {};

    ifstream InPutFail("input.txt");
    ofstream OutPutFail("output.txt");

    InPutFail >> N;

    for (int i = 0; i < N; i++) {
        InPutFail >> st;
        if (st != "COUNT") {
            InPutFail >> Element;
            if (st == "ADD") {
                ArrMass.insert(Element);
            }
            else {
                if (ArrMass.count(Element)) {
                    OutPutFail << "YES" << "\n";
                }
                else {
                    OutPutFail << "NO" << "\n";
                }
            }
        }
        else {
            OutPutFail << ArrMass.size() << "\n";
        }
    }

}
