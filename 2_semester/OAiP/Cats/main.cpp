#include <fstream>
#include <vector>
#include <string>
using namespace std;
int const LEN = 3;
int const ALPHLEN = 52;
int idx(char CharElement);
void SortWithDepth(vector<string*> &Bucket, int Lvl);
void BucketSort(vector<string> &Arr, int Size);
int main();
int idx(char CharElement) {
    if('A' <= CharElement && CharElement <= 'Z') {
        return (CharElement - 'A');
    }
    return (CharElement - 'a' + 26);
}
void SortWithDepth(vector<string*> &Bucket, int Lvl) {
    if(Bucket.empty() || (Lvl == 0)) {
        return;
    }
    vector<vector<string*>> NextLayer(ALPHLEN);
    int Index = LEN - Lvl;
    for(auto &CharWord : Bucket) {
        NextLayer[idx((*CharWord)[Index])].push_back(CharWord);
    }
    int Count = 0;
    for(int i = 0; i < ALPHLEN; ++i) {
        SortWithDepth(NextLayer[i], Lvl - 1);
        for(auto &word : NextLayer[i]) {
            Bucket[Count] = word;
            ++Count;
        }
    }
}
void BucketSort(vector<string> &Arr, int Size) {
    vector<string *> Pointers(Size);
    for (int i = 0; i < Size; ++i) {
        Pointers[i] = &Arr[i];
    }
    SortWithDepth(Pointers, LEN);
    vector<string> AnswersChars(Size);
    for(int i = 0; i < Size; ++i) {
        AnswersChars[i] = *Pointers[i];
    }
    for(int i = 0; i < Size; ++i) {
        Arr[i] = AnswersChars[i];
    }
}
int main() {
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    int N;
    InPut >> N;
    vector<string> ArrStr(N);
    for (int i = 0; i < N; i++){
        InPut >> ArrStr[i];
    }
    BucketSort(ArrStr, N);
    for (int i = 0; i < N; i++){
        OutPut << ArrStr[i] << endl;
    }
    InPut.close();OutPut.close();
}
