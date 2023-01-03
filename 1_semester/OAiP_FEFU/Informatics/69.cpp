//Задача №69. Переставить элементы в обратном порядке
//Напишите программу, которая переставляет элементы массива в обратном порядке без использования дополнительного массива.
// Программа должна считать массив, поменять порядок его элементов, затем вывести результат
// (просто вывести элементы массива в обратном порядке – недостаточно!)
//Входные данные
//Сначала задано число N — количество элементов в массиве (1≤N≤35). Далее через пробел записаны N чисел — элементы массива. Массив состоит из целых чисел.
#include <iostream>
#include <cmath>

using namespace std;
int main(){
    int CountElementInArrN; int * ArrN;
    do {
        cin >> CountElementInArrN;
        if (CountElementInArrN < 1 || CountElementInArrN > 35) cout << "1<=x<=35 !!! Repeat please...\n";
    }
    while (CountElementInArrN < 1 || CountElementInArrN > 35);
    ArrN = (int *) malloc(sizeof(int) * CountElementInArrN);
        for (int i = 0; i < CountElementInArrN; i++){
            cin >> ArrN[i];
        }
        for (int i = 0; i < CountElementInArrN/2; i++) {
            swap(ArrN[i], ArrN[CountElementInArrN - 1 - i]);
        }
        for (int u = 0; u < CountElementInArrN; u++) {
            cout << ArrN[u] << " ";
        }
    cout <<endl;
    delete []ArrN;
    system("pause");
    return 0;


}
