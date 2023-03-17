#include <iostream>
#include <windows.h>
#include <math.h>
#include <cstring>
using namespace std;
int Task1();
int Task2();
int Task3();
int Task4();
int Task5();
int SortingBySelection2(int * Array, int CountElement, int Invers);
int SortingBySelection1(int * Array, int CountElement, int Invers);
void Countsort(int arr[], int n, int k, bool Flag);
int CompareIntegers(const void* first, const void* second);
void BucketSort(int array[], int n, bool Flag);
void RadixSortAlgo(int a[], int size_of_a, bool Flag);
struct bucket;
void Swap(int* a, int* b);
void Heapify(int arr[], int N, int i);
void HeapSort(int arr[], int N);
void PrintArray(int arr[], int N, bool Flag);
int main(){
    Task1(); //Введите номер необходимого задания
}
int Task1(){
    SetConsoleOutputCP(CP_UTF8);
    int CountElements, Inversis = 0, SortClass;
    cout << "Введите необходимое количество элементов:\n"; cin >> CountElements;
    if (CountElements < 6){
        cout << "Введите количество элементов превышающее или равное 6";
        return 0;
    }
    cout << "Введите элементы:\n";
    int Arr[CountElements];
    for (int i = 0; i < CountElements; i++){
        cin >> Arr[i];
        if (i > CountElements){
            break;
        }
    }
    cout << "Изначальный массив:   ";
    for (int i = 0; i < CountElements; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
    cout << "Отсортировать в убывающем порядке - 1\n Отсортировать в возраствющем порядке - 2" << endl;
    cin >> SortClass;
    cout << "\n" << "Сортировка отбором, и количество инверсий:  ";
    if (SortClass == 1){
         cout << SortingBySelection1(Arr, CountElements, Inversis);
    }
    if (SortClass == 2){
        cout << SortingBySelection2(Arr, CountElements, Inversis);
    }


}
int Task2(){
    SetConsoleOutputCP(CP_UTF8);
    int CountElements, Inversis = 0;
    bool SortClass;
    cout << "Введите необходимое количество элементов:\n"; cin >> CountElements;
    if (CountElements < 6){
        cout << "Введите количество элементов превышающее или равное 6";
        return 0;
    }
    cout << "Введите элементы:\n";
    int Arr[CountElements];
    for (int i = 0; i < CountElements; i++){
        cin >> Arr[i];
        if (i > CountElements){
            break;
        }
    }
    cout << "Изначальный массив:   ";
    for (int i = 0; i < CountElements; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
    cout << "Отсортировать в убывающем порядке - 0\nОтсортировать в возраствющем порядке - 1" << endl;
    cin >> SortClass;
    cout << "\n" << "Сортировка подсчетом:  ";
    Countsort(Arr, CountElements, 100000, SortClass);
}

int Task3(){
    SetConsoleOutputCP(CP_UTF8);
    int CountElements, Inversis = 0;
    bool SortClass;
    cout << "Введите необходимое количество элементов:\n"; cin >> CountElements;
    if (CountElements < 6){
        cout << "Введите количество элементов превышающее или равное 6";
        return 0;
    }
    cout << "Введите элементы:\n";
    int Arr[CountElements];
    for (int i = 0; i < CountElements; i++){
        cin >> Arr[i];
        if (i > CountElements){
            break;
        }
    }
    cout << "Изначальный массив:   ";
    for (int i = 0; i < CountElements; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
    cout << "Отсортировать в убывающем порядке - 1\nОтсортировать в возраствющем порядке - 0" << endl;
    cin >> SortClass;
    cout << "\n" << "Сортировка караманная:  ";
    BucketSort(Arr, CountElements, SortClass);
}

int Task4(){
    SetConsoleOutputCP(CP_UTF8);
    int CountElements, Inversis = 0;
    bool SortClass;
    cout << "Введите необходимое количество элементов:\n"; cin >> CountElements;
    if (CountElements < 6){
        cout << "Введите количество элементов превышающее или равное 6";
        return 0;
    }
    cout << "Введите элементы:\n";
    int Arr[CountElements];
    for (int i = 0; i < CountElements; i++){
        cin >> Arr[i];
        if (i > CountElements){
            break;
        }
    }
    cout << "Изначальный массив:   ";
    for (int i = 0; i < CountElements; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
    cout << "Отсортировать в убывающем порядке - 1\nОтсортировать в возраствющем порядке - 0" << endl;
    cin >> SortClass;
    cout << "\n" << "Поразрядная сортировка:  ";
    RadixSortAlgo(Arr, CountElements, SortClass);

}

int Task5(){
    SetConsoleOutputCP(CP_UTF8);
    int CountElements, Inversis = 0;
    bool SortClass;
    cout << "Введите необходимое количество элементов:\n"; cin >> CountElements;
    if (CountElements < 6){
        cout << "Введите количество элементов превышающее или равное 6";
        return 0;
    }
    cout << "Введите элементы:\n";
    int Arr[CountElements];
    for (int i = 0; i < CountElements; i++){
        cin >> Arr[i];
        if (i > CountElements){
            break;
        }
    }
    cout << "Изначальный массив:   ";
    for (int i = 0; i < CountElements; i++){
        cout << Arr[i] << " ";
    }
    cout << endl;
    cout << "Отсортировать в убывающем порядке - 1\nОтсортировать в возраствющем порядке - 0" << endl;
    cin >> SortClass;
    cout << "\n" << "Поразрядная сортировка:  ";
    HeapSort(Arr, CountElements);
    PrintArray(Arr, CountElements, SortClass);
}

int SortingBySelection2(int * Array, int CountElement, int Invers){
    for (int i = 0; i < CountElement; i++){
        int Temp = Array[0];
        for (int j = i + 1; j < CountElement; j++){
            if (Array[i] > Array[j]){
                Invers++;
                Temp = Array[i];
                Array[i] = Array[j];
                Array[j] = Temp;}
        }
    }
    for (int i = 0; i < CountElement; i++){
        cout << Array[i] << " ";
    }
    cout << endl;
    return Invers;

}
int SortingBySelection1(int * Array, int CountElement, int Invers){
    for (int i = 0; i < CountElement; i++){
        int Temp = Array[0];
        for (int j = i + 1; j < CountElement; j++){
            if (Array[i] < Array[j]){
                Invers++;
                Temp = Array[i];
                Array[i] = Array[j];
                Array[j] = Temp;}
        }
    }
    for (int i = 0; i < CountElement; i++){
        cout << Array[i] << " ";
    }
    cout << endl;
    return Invers;

}
void Countsort(int arr[], int n, int k, bool Flag){
    int output[n];
    int freq[k + 1];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    int total = 0;
    for (int i = 0; i < k + 1; i++)
    {
        int oldCount = freq[i];
        freq[i] = total;
        total += oldCount;
    }
    for (int i = 0; i < n; i++){
        output[freq[arr[i]]] = arr[i];
        freq[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {arr[i] = output[i];}
    if (Flag == 1){
       for (int i = 0; i < n; i++){
        cout << arr[i] << " ";}
    }
    if (Flag == 0){
        for (int i = n - 1; i >= 0; i--){
            cout << arr[i] << " ";
        }
    }
}
struct bucket{
    int count;
    int* value;
};

int CompareIntegers(const void* first, const void* second){
    int x = *((int*)first), y =  *((int*)second);
    if (x == y){return 0;}
    else if (x < y){ return -1;}
    else return 1;
}

void BucketSort(int array[], int n, bool Flag){
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++){
        if (array[i] < 0){
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10){
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else{
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++){
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &CompareIntegers);
        for (j = 0; j < buckets[i].count; j++){
            array[k + j] = buckets[i].value[j];
        }
        k += buckets[i].count;
        free(buckets[i].value);
    }
    if (Flag == 0){
        for (int i = 0; i < n; i++){
            cout << array[i] << " ";
        }
    }
    else{
        for (int i = n - 1 ; i >= 0; i--){
            cout << array[i] << " ";
        }
    }

}

void RadixSortAlgo(int a[], int size_of_a, bool Flag){
    int maximumNumber = a[0];
    for(int i=1;i<size_of_a;i++){
        maximumNumber = max(maximumNumber, a[i]);
    }
    int digitsCount = 0;
    while(maximumNumber > 0){
        digitsCount++;
        maximumNumber /= 10;
    }
    for(int i=0;i<digitsCount;i++){
        int pwr = pow(10, i);
        int new_a[size_of_a];
        int count_array[10];
        memset(count_array, 0, sizeof(count_array));
        for(int j=0;j<size_of_a;j++){
            int num = (a[j]/pwr) % 10;
            count_array[num]++;
        }
        for(int j=1;j<10;j++){
            count_array[j] += count_array[j-1];
        }
        for(int j=size_of_a-1;j>=0;j--){
            int num = (a[j]/pwr) % 10;
            new_a[count_array[num]-1] = a[j];
            count_array[num]--;
        }
        for(int j=0;j<size_of_a;j++)
            a[j] = new_a[j];
    }
    if (Flag == 0){
        for (int i = 0; i < size_of_a; i++){
            cout << a[i] << " ";
        }
    }
    if (Flag == 1){
        for (int i = size_of_a - 1; i >= 0; i--){
            cout << a[i] << " ";
        }
    }
    cout<<endl;
}
void Swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Heapify(int arr[], int N, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {

        Swap(&arr[i], &arr[largest]);
        Heapify(arr, N, largest);
    }
}
void HeapSort(int arr[], int N){
    for (int i = N / 2 - 1; i >= 0; i--)
        Heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        Swap(&arr[0], &arr[i]);
        Heapify(arr, i, 0);
    }
}
void PrintArray(int arr[], int N, bool Flag){
    if (Flag == 0){
        for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    }
    if (Flag == 1){
        for (int i = N - 1; i >= 0; i--)
        cout << arr[i] << " ";
    }
}