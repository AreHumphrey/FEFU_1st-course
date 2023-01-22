//int MinRazn(int Arr[], int a, size_t n){
//    int Razn = INT_MAX;
//    int index = 0;
//    for (int i = 0; i < n; i++){
//        if ((abs(a - Arr[i])) < Razn){
//            Razn = (abs(a - Arr[i]));
//            index = i + 1;
//        }
//        if (abs(a - Arr[i]) == 0){
//            break;
//        }
//    }
//    return index;
//}
//К сожалению тупой перебор не работает :(
//Придется Использовать сортировку слияниями:
//Сортировка слиянием — алгоритм сортировки, который упорядочивает списки (или другие структуры данных, доступ к элементам которых можно получать только последовательно, например — потоки) в определённом порядке.
//Слияние означает объединение двух (или более) последовательностей в одну упорядоченную последовательность при помощи циклического выбора элементов, доступных в данный момент.
//Взято с первого попавшего сайтика https://prog-cpp.ru/sort-merge/
struct Obgect{
    int ObgectCur;
    int CurrentIndex;
};
void mergesort(struct Obgect * a, int l, int r)
{
    if (l == r) return; // границы сомкнулись
    int mid = (l + r) / 2; // определяем середину последовательности
    // и рекурсивно вызываем функцию сортировки для каждой половины
    mergesort(a, l, mid);
    mergesort(a, mid + 1, r);
    int i = l;  // начало первого пути
    int j = mid + 1; // начало второго пути
    struct Obgect tmp[r]; // дополнительный массив
    for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
    {
        // записываем в формируемую последовательность меньший из элементов двух путей
        // или остаток первого пути если j > r
        if ((j > r) || ((i <= mid) && (a[i].ObgectCur < a[j].ObgectCur)))
        {
            tmp[step] = a[i];
            i++;
        }
        else
        {
            tmp[step] = a[j];
            j++;
        }
    }
    // переписываем сформированную последовательность в исходный массив
    for (int step = 0; step < r - l + 1; step++)
        a[l + step] = tmp[step];
}
#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE * InPut = fopen("shelter.in", "r");
    FILE * OutPut = fopen("shelter.out", "w");
    int SizeOfHouse, SizeOfBomb;
    fscanf(InPut, "%d", &SizeOfHouse);
    struct Obgect ArrHouse[SizeOfHouse];

    for (int i = 0; i < SizeOfHouse; i++){
        fscanf(InPut,"%d", &ArrHouse[i].ObgectCur);
        ArrHouse[i].CurrentIndex = i + 1;
    }
    fscanf(InPut, "%d", &SizeOfBomb);
    struct Obgect ArrBomb[SizeOfBomb];
    for (int i = 0; i < SizeOfBomb; i++){
        fscanf(InPut, "%d", &ArrBomb[i].ObgectCur);
        ArrBomb[i].CurrentIndex = i + 1;
    }
    mergesort(ArrHouse, 0, SizeOfHouse - 1);
    mergesort(ArrBomb, 0, SizeOfBomb - 1);
    int C = 0;
    int Len, MinLen;
    int Arr[SizeOfHouse];
    for (int i = 0; i < SizeOfHouse; i++){
        MinLen = abs(ArrHouse[i].ObgectCur - ArrBomb[C].ObgectCur);
        Len = abs(ArrHouse[i].ObgectCur - ArrBomb[C + 1].ObgectCur);
        while (MinLen >= Len){
            C ++;
            MinLen = Len;
            Len = abs(ArrHouse[i].ObgectCur - ArrBomb[C + 1].ObgectCur);
            if (C == SizeOfBomb){
                for (int j = i; j < SizeOfHouse; j++){
                    Arr[ArrHouse[j].CurrentIndex] = ArrBomb[C].CurrentIndex;
                }
                return 0;
            }
        }
        Arr[ArrHouse[i].CurrentIndex] = ArrBomb[C].CurrentIndex;
    }
    for (int i = 1; i < SizeOfHouse + 1;i++){
        fprintf(OutPut, "%d ", Arr[i]);
    }


}
