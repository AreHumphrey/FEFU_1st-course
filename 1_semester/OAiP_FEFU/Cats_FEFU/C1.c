#include <stdio.h>
#include <windows.h>
int main(){
    int N;
    FILE*FailIn; FILE* FailOut;
    FailIn= fopen("input.txt", "r");
    FailOut = fopen("output.txt", "w");
    fscanf(FailIn, "%d", &N);
    int Arr1[N + 1], ArrNum[N];
    Arr1[0] = 0;
    for (int i = 0; i < N; i++){
        fscanf(FailIn, "%d", &ArrNum[i]);
        Arr1[i + 1] = ArrNum[i] + Arr1[i];
    }
    int MSumma, SummaItog = 0;
    fscanf(FailIn, "%d", &MSumma);
    for (int j = 0; j < MSumma; j++){
        int l, r;
        fscanf(FailIn, "%d", &l); fscanf(FailIn, "%d", &r);
        SummaItog = Arr1[r] - Arr1[l - 1];
        fprintf(FailOut,"%d ",  SummaItog);
    }


}