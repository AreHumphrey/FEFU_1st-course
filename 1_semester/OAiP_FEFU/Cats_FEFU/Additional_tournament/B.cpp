#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string text;

    ifstream InPut("input.txt");
    ofstream OutPut("output.txt", ios::out);

    string perexod;
    int N;

    getline(InPut, text);
    getline(InPut, perexod);

    N = stoi(perexod);

    string text_f[N];

    for (int i = 0; i < N; i++){
        getline(InPut, text_f[i]);
        if (text.find(text_f[i]) >= 0 and text.find(text_f[i]) < 250001){
            OutPut << 1 << " ";
        }else{
            OutPut << 0 << " ";
        }
    }

    InPut.close();
    OutPut.close();
}
