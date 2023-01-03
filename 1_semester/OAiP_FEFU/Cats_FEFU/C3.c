#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    size_t SIZE;
    int Element; int ArrNumbers[2001] = {}; //может быть только 2000 чисел, так как -1000 <= ai <= 1000
    fscanf(InPut, "%llu", &SIZE);//прибавляем к диапазону 1000, так как не может залесть в отрицательные числа
    for (int i = 0; i < SIZE; ++i) {
        fscanf(InPut, "%d", &Element);//каждый встетившийся элемент - счетчик данного числа
        ++ArrNumbers[Element + 1000];
    }


    for (int i = 0; i != 2001; ++i){ //вывод в порядку возрастания в случае наличия числа
        if (ArrNumbers[i]){
            fprintf(OutPut, "%d %d\n", i -1000, ArrNumbers[i]);
        }
    }
}



