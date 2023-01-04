#include <stdio.h>
int NOD(int a, int b){
    while (a != b){
        if (a > b){a = a - b;}
        if (a < b){b = b - a;}
    }
    return a;
}
int NOK(int a, int b){
    return ((a * b)/ (NOD(a, b)));
}
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int a, b;
    fscanf(InPut, "%d", &a); fscanf(InPut, "%d", &b);
    fprintf(OutPut, "%d %d", NOD(a, b), NOK(a, b));
    fclose(InPut); fclose(OutPut);

}
