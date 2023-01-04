#include <stdio.h>
int main(){
    FILE* FailIn = fopen("input.txt", "r");
    FILE* FailOut = fopen("output.txt", "w");
    char ArrOpen[5] = {0, 0 , 0, 0, 0}, ArrEx[5] = {};
    int Flag = 0;
    for (int i = 0; i < 5; i++){
        ArrOpen[i] = getc(FailIn);
        if (ArrOpen[i] == '=' && Flag == 0){
            ArrEx[i] = '*';
            continue;
        }
        if (ArrOpen[i] == '=' && Flag == 1){
            ArrEx[i] = '-';
            continue;
        }
        if (ArrOpen[i] == '=' && Flag == 2){
            ArrEx[i] = '+';
            continue;
        }
        if (ArrOpen[i] == 62 && Flag == 0){
            ArrEx[i] = '-';
            Flag = 1;
            continue;
        }
        if (ArrOpen[i] == 60 && Flag == 0){
            ArrEx[i] = '+';
            Flag = 2;
            continue;
        }
        if (ArrOpen[i] == 60 && Flag == 2){
            ArrEx[i] = '+';
//            Flag = 1;
            continue;
        }
        if (ArrOpen[i] == 62 && Flag == 1){
            ArrEx[i] = '-';
//            Flag = 2;
            continue;
        }
        if (ArrOpen[i] == 62 && Flag == 2){
            ArrEx[i] = '?';
            Flag = 3;
            continue;
        }
        if (ArrOpen[i] == 60 && Flag == 1){
            ArrEx[i] = '?';
            Flag = 3;
            continue;
        }
        if (Flag == 3){
            ArrEx[i] = '?';
            continue;
        }
    }
    for (int i = 0; i < 5; i++){
        fprintf(FailOut, "%c", ArrEx[i]);
    }

}
