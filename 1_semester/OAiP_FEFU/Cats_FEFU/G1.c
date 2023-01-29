#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int max(int x, int y){
    return (x > y) ? x : y;
}
int main(){
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int CountOfElements, CountOfOperation;
    fscanf(InPut, "%d", &CountOfElements);
    int StDBinTrees = (int)(pow(2, ceil(log2(CountOfElements)))); //Доводим данное число до степени двойки
    int ArrTreesz[StDBinTrees * 2];
    for (int i = StDBinTrees; i < StDBinTrees * 2; i++){
        if (i < CountOfElements + StDBinTrees){
            fscanf(InPut, "%d", &ArrTreesz[i]);
        } else{
            ArrTreesz[i] = - (float)('inf');
        }
    }//Мы никогда не используем ячейку с индексом 0
    //Теперь необходимо построить дерево отрезков:
    for (int i = StDBinTrees - 1; i > 0; i--){
        ArrTreesz[i] = max(ArrTreesz[i * 2], ArrTreesz[i * 2 + 1]);//локальные максимумы
    }
    fscanf(InPut, "%d", &CountOfOperation);
    int MoveLeft = 0, MoveRight = 0;
    int ArrFinish[CountOfOperation], MaxElements = ArrTreesz[StDBinTrees];
    char Move;
    fscanf(InPut, "%c", &Move);
    for (int i = 0; i < CountOfOperation; i++){
        fscanf(InPut, "%c", &Move);
        if (Move == 'R'){
            MoveRight++;
        } else{
            MoveLeft++;
        }
        int RightIndex = StDBinTrees + MoveRight;
        int LeftIndex = StDBinTrees + MoveLeft;
        while (LeftIndex < RightIndex - 1){
            // Если левая или правая граница нечётна или чётна соответственно,
            // то они "захватывают" не всю пару чисел, а лишь одно число из неё
            if (RightIndex % 2 == 0)
            {
                MaxElements = max(MaxElements, ArrTreesz[RightIndex]); // граница "правого частичного" участка
            } // Если захватывает лишь частично
            if (LeftIndex % 2 == 1)
            {
                MaxElements = max(MaxElements, ArrTreesz[LeftIndex]); // граница "левого частичного" участка
            } // Если захватывает лишь частично

            LeftIndex = (LeftIndex + 1) / 2; // Сдвижение к максимумам вверх
            RightIndex = (RightIndex - 1) / 2; // Сдвижение к максимумам вниз
        } // Сведение всего к одному из двух нижеизложенных варианта

        if (LeftIndex == RightIndex)
        {
            MaxElements = max(MaxElements, ArrTreesz[RightIndex]); // Сравнение максимумов пар или же элементов одной пары
        } // Одна точка
        else if (LeftIndex == RightIndex - 1)
        {
            MaxElements = max(MaxElements, max(ArrTreesz[LeftIndex], ArrTreesz[RightIndex]));
        } // Две точки


        ArrFinish[i] = MaxElements;
        MaxElements = -1000000000;
    }
    for (int i = 0; i < CountOfOperation; i++){
        fprintf(OutPut, "%d ", ArrFinish[i]);
    }

}
