#include "library.h"
#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;
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
void countsort(int arr[], int n, int k, bool Flag)
{
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
    for (int i = 0; i < n; i++)
    {
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
struct bucket
{
    int count;
    int* value;
};

int compareIntegers(const void* first, const void* second)
{
    int x = *((int*)first), y =  *((int*)second);
    if (x == y)
    {
        return 0;
    }
    else if (x < y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void bucketSort(int array[],int n, bool Flag)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].value = (int*)malloc(sizeof(int) * n);
    }

    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].value[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].value[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].value[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        qsort(buckets[i].value, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
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

void radixSortAlgo(int a[], int size_of_a, bool Flag){
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
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {

        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int N, bool Flag)
{
    if (Flag == 0){
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
    }
    if (Flag == 1){
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i] << " ";
    }
}
