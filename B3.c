#include <stdio.h>
#include <windows.h>
int main(){
    int SummaChisel = 0, ScanElement, Count;
    FILE*FailIn; FILE* FailOut;
    FailIn= fopen("input.txt ", "r");
    FailOut = fopen("output.txt", "w");
    fscanf(FailIn, "%d", &Count);
    for (int i = 0; i < Count; i++){
        fscanf(FailIn, "%d", &ScanElement);
        SummaChisel += ScanElement;
    }
    fprintf(FailOut, "%d", SummaChisel);

    fclose(FailIn);
    fclose(FailOut);


}
