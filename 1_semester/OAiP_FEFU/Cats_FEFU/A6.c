#include <stdio.h>
#include <stdlib.h>
void AnyColorsCube (FILE * OutPut, int CountCube);
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int CountCube;
    fscanf(InPut, "%d", &CountCube);
    AnyColorsCube(OutPut, CountCube);
    fclose(OutPut);
    fclose(InPut);
}
void AnyColorsCube (FILE * OutPut, int CountCube){
    for (int i = 0; i < CountCube; i++){
        for (int j = 0; j < CountCube; j++){
            for (int y = 0; y < CountCube; y++){
                fprintf(OutPut, "%d ", 1 + (i + j + y) % CountCube);
            }
            fprintf(OutPut, "\n");
        }
    }
}
