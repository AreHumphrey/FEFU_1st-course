#include <iostream>
#include <fstream>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "");
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    int ArrS[256] = {};
    char S1;
    int SizeStr = 0, Min = INT_MAX;
    while(InPut.eof() == false) {
        InPut >> noskipws >> S1;
        ArrS[(int)S1]++;
        SizeStr++;
    }
    S1 = 0;
    for(int i = 0; i < 256;i++){
        for(int j = 0; j < 256;j++) {
            if((ArrS[j] > 0) && (ArrS[j] < Min)){
                Min = ArrS[j];
                S1 = (char)j;
            }
        }
        if(S1 != 0){
            OutPut << "------------------------" << endl;
            OutPut << S1 << " < Значение " << endl << Min << " : Количество " << endl << setprecision(3) << ((float)Min / SizeStr) * 100 << "% : Процент встречаемости по тексту" << endl;
            OutPut << "________________________" << endl;
            Min = INT_MAX;
            ArrS[(int)S1] = 0;
            S1 = 0;
        }
    }
    OutPut << SizeStr << " : Общий размер";
}

