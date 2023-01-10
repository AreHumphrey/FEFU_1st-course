#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int N;
    fscanf(InPut, "%d", &N);
    int PowN = pow(2, N), i = 0;
    int Temp; int *ArrBin;
    ArrBin = (int *) malloc(sizeof (int) * N);
    while (i < PowN){
        Temp = i;
        for (int j = N - 1; j >= 0; j--){
            ArrBin[j] = Temp % 2;
            Temp /= 2;
        }
        i++;
        for (int g = 0; g < N; g++){
            fprintf(OutPut, "%d", ArrBin[g]);
        }
        fprintf(OutPut, "\n");
    }


}

