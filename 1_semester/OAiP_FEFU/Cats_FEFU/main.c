#include <stdio.h>

int main()
{
    FILE * InPut = fopen("function.in", "r");
    FILE * OutPut = fopen("function.out", "w");
    char ArrString[4];
    int n, Art;
    fscanf(InPut, "%d", &n); fgetc(InPut);
    for (int i = 0; i < 4; i++){
        ArrString[i] = fgetc(InPut);
        //printf("%d ", (int)ArrString[i]);
    }

    for(int i = 0; i < 4; i++) {
        printf("%c ", ArrString[i]);
    }

    if ((int)ArrString[3] - 48){
        for (int i = 0; i < n; i++){
            fprintf(OutPut,  "1");
        }
    }
    else if ((int)ArrString[1] - 48){
        fprintf(OutPut, "%d", n % 2);
        for (int i = 1; i < n; i++){
            fprintf(OutPut,  "1");
        }
    }
    else if ((int)ArrString[0] - 48){
        for (int i = 1; i < n; i++) fprintf(OutPut,  "1");
        fprintf(OutPut, "0");
    }
    else if ((int)ArrString[2] - 48){
        fprintf(OutPut, "1");
        for (int i = 1; i < n; i++) fprintf(OutPut, "0");

    }
    else fprintf(OutPut,  "No solution");
    //return 0;
}
