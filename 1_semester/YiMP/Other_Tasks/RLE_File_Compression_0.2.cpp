#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    char Letter;
    int Count = 0;
    int Size;
    vector<char> ArrLetter;
    while(InPut.eof() == false){
        InPut >> Letter >> ws;
        ArrLetter.push_back(Letter);
    }
    Size = ArrLetter.size();
    for(int i = 0; i < Size; i++) {
        if(ArrLetter[i] == ArrLetter[i + 1]){
            Count ++;
            if(ArrLetter[i + 1] != ArrLetter[i + 2]){
                Count ++;
                OutPut << Count << ArrLetter[i];
                i++;
                Count = 0;
                continue;
            }
        }
        else{
            Count++;
            if(ArrLetter[i + 1] == ArrLetter[i + 2]){
                OutPut << Count;
                for(int j = Count; j > 0; j--){
                    OutPut << ArrLetter[i - (j - 1)];
                }
                Count = 0;
            }
            continue;
        }
    }
}
