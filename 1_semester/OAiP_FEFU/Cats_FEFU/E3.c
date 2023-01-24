#include <stdio.h>
#include <stdlib.h>
#define max(X, Y) (((X) > (Y)) ? (X) : (Y))
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    long long N, R, Middle, Ziro = 0;
    long long * ArrSpiralLine;
    fscanf(InPut, "%lld", &N);
    fscanf(InPut, "%lld", &R);
    ArrSpiralLine = (long long *) calloc(  N , sizeof (long long));
    Middle = N / 2 + N % 2;

    if (R <= Middle){
        ArrSpiralLine[R - 1] = (N - (R - 1) * 2) * (N - (R - 1) * 2);
        for (long long i = max(Ziro, R - 2); i <= N - R; i++){
            ArrSpiralLine[i] = ArrSpiralLine[R - 1] + (R - i - 1);
        }
    } else{
        ArrSpiralLine[R - 1] = ((N - (R - 1) * 2 - 1) * (N - (R - 1) * 2 - 1) + 1);
        for (long long i = R - 2; i >= N - R; i--){
            ArrSpiralLine[i] = ArrSpiralLine[R - 1] - R + i + 1;
        }
    }
    for (long long i = 0; i < Middle; i++){
        if (ArrSpiralLine[i] != 0){
            break;
        } else{
            ArrSpiralLine[i] = (N - i * 2) * (N - i * 2) - ((N - i * 2) - 1) * 4 + R - 1 - i;
        }
    }
    for (long long i = 0; i < Middle; i++){
        if (ArrSpiralLine[N - 1 - i] != 0){
            break;
        } else{
            ArrSpiralLine[N - 1 - i] = (N - i * 2) * (N - i * 2) - (N - i * 2) - R + i + 2;

        }
    }
    for (long long i = 0; i < N; i++){
        fprintf(OutPut, "%lld ", ArrSpiralLine[i]);
    }
}
