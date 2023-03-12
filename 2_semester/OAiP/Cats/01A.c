#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int CountEteresh = 0, Flag = 0;
    char * ArrWords = (char*)malloc(sizeof (char ));
    while (!feof(InPut)){
        ArrWords = (char *) realloc(ArrWords, sizeof(char ));
        fscanf(InPut, "%c", &ArrWords[CountEteresh]);
        CountEteresh += 1;
    }
    for (int i = 0; i != CountEteresh - 1; i++){
        if (ArrWords[i] >= 'A' && ArrWords[i] <= 'Z'){
            Flag = 1;
        }
        if (ArrWords[i] >= 'a' && ArrWords[i] <= 'z' && Flag == 1){
            fprintf(OutPut, "NO\n");
            return 0;
        }
    }
    fprintf(OutPut, "YES");
    fclose(InPut);
    fclose(OutPut);

}
