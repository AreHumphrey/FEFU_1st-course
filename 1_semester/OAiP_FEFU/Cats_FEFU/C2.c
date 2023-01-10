#include <stdio.h>
#include <stdlib.h>
int max(int x, int y){
    return (x > y) ? x : y;

}
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int SizeSequence;
    fscanf(InPut, "%llu", &SizeSequence);
    int * ArrSequence; int *ArrFirst; int *ArrSecond; int Count1 = 0, Count2 = 0;
    ArrSequence = (int *) calloc(SizeSequence + 2, sizeof(int));
    ArrFirst = (int *)calloc(SizeSequence, sizeof (int));
    ArrSecond = (int*)calloc(SizeSequence, sizeof (int));
    for (int i = 1; i != SizeSequence + 1; i++){
        fscanf(InPut, "%d", &ArrSequence[i]);
        ArrFirst[i - 1] = ArrSequence[i];
        ArrSecond[i - 1] = ArrSequence[i];
    }
    ArrSequence[0] = ArrSequence[1] - 1;
    ArrSequence[SizeSequence + 1] = ArrSequence[SizeSequence] - 1;
    for (int i = 0; i < SizeSequence; i++){
        if (i % 2 == 0){
            ArrFirst[i] = max(ArrSequence[i + 1], max(ArrSequence[i], ArrSequence[i + 2]) + 1);
        }
        else{
            ArrSecond[i] = max(ArrSequence[i + 1], max(ArrSequence[i], ArrSequence[i + 2]) + 1);
        }
        Count1 += ArrFirst[i];
        Count2 += ArrSecond[i];
    }
    if (Count1 < Count2){
        for (int i = 0; i < SizeSequence; i++){
            fprintf(OutPut, "%d ", ArrFirst[i]);
        }
    }
    else{
        for (int i = 0;  i < SizeSequence; i++){
            fprintf(OutPut, "%d ", ArrSecond[i]);
        }
    }
    free(ArrSequence);free(ArrSecond); free(ArrFirst);
    fclose(InPut);fclose(OutPut);
}
//Код не мой(
