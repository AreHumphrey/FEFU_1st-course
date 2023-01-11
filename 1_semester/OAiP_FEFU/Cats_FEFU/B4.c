#include <stdio.h>
int main() {
    int NumberX, ReturnBitK, BitRezult;
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    fscanf(InPut, "%d", &NumberX);
    fscanf(InPut, "%d", &ReturnBitK);
    if (ReturnBitK > 31){
        fprintf(OutPut, "%d", 0);
    } else {
        BitRezult = (NumberX >> ReturnBitK) & 1;
        fprintf(OutPut, "%d", BitRezult);
    }
    fclose(InPut);fclose(OutPut);

}
