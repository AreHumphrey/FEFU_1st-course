#include <stdio.h>
#include <stdlib.h>
//int check(int massive[],int CountArr, int chsl) {
//    int i = 0;
//    while (i != CountArr){
//        if (chsl==massive[i]){
//            return i;
//        }
//        i++;
//    }
//        return -1; //Не проходит про времени, поэтому использую бинарный поиск
//    }
int Seachbinary(int arr[], int left, int right, int key, int size){
	int midd = 0;
	for (int i = 0; i <= size; i++){
		midd = (left + right) / 2;
		if (key < arr[midd]) {
			right = midd - 1;
		}
		else if (key > arr[midd]) {
			left = midd + 1;
		}
		else {
			return midd;
		}
		if (left > right) { return -1; }
	}
}
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int SizeA, SizeB, SizeC, CountRepeatingElements = 0; int * ArrA; int * ArrB; int *ArrC;
    fscanf(InPut, "%d", &SizeA);
    fscanf(InPut, "%d", &SizeB);
    fscanf(InPut, "%d", &SizeC),
//    printf("%d, %d, %d", SizeA, SizeB, SizeC);
    ArrA = (int*)malloc(sizeof(int)*SizeA);
    ArrB = (int*)malloc(sizeof(int)*SizeB);
    ArrC = (int*)malloc(sizeof(int)*SizeC);
    for (int i = 0; i < SizeA; i++){
        fscanf(InPut, "%d", &ArrA[i]);
//        printf("%d ", ArrA[i]);
    }
    for (int i = 0; i < SizeB; i++){
        fscanf(InPut, "%d", &ArrB[i]);
    }
    for (int i = 0; i < SizeC; i++){
        fscanf(InPut, "%d", &ArrC[i]);
    }
    for (int i = 0; i < SizeA; i++){
        if (Seachbinary(ArrB, 0, SizeB, ArrA[i], SizeB) != -1){
            if (Seachbinary(ArrC, 0, SizeC, ArrA[i], SizeC) != -1){
                CountRepeatingElements += 1;}//Если встречается в обоих массивах увеличиваю количество 
        }
        //делать проверку третьего массива только если элемент есть во втором
    }
    fprintf(OutPut, "%d", CountRepeatingElements);



}
