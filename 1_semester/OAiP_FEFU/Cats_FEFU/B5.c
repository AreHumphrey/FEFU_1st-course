#include <stdio.h>
int main() {
    FILE * Input = fopen("input.txt","r");
    FILE * OutPut = fopen("output.txt", "w");
    float Number;
    fscanf(Input, "%f", &Number);
    int * l= (int *) &Number;
    int BinaryOrder = ((*l >> 23) & 255) - 127;
    if (Number == 0){
        BinaryOrder = 0;
    } else if (BinaryOrder < -126) {
        BinaryOrder = -126;
    }
    fprintf(OutPut, "%d", BinaryOrder);
}
