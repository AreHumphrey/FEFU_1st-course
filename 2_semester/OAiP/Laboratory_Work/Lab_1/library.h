#ifndef LIBRARY_LAB1_LIBRARY_H
#define LIBRARY_LAB1_LIBRARY_H

int SortingBySelection2(int * Array, int CountElement, int Invers);
int SortingBySelection1(int * Array, int CountElement, int Invers);
void countsort(int arr[], int n, int k, bool Flag);
int compareIntegers(const void* first, const void* second);
void bucketSort(int array[],int n, bool Flag);
void radixSortAlgo(int a[], int size_of_a, bool Flag);
struct bucket;
void swap(int* a, int* b);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);
void printArray(int arr[], int N, bool Flag);
#endif //LIBRARY_LAB1_LIBRARY_H
