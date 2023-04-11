#include <iostream>

void swap(int *a, int i, int j) {
    int s = a[i];
    a[i] = a[j];
    a[j] = s;
}

void Print(int *a, int n) {
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

bool Permutation(int *a, int n) {
    int j = n - 2;
    while (j != -1 && a[j] >= a[j + 1])
        j--;
    if (j == -1)
        return false; 
    int k = n - 1;
    while (a[j] >= a[k])
        k--;
    swap(a, j, k);
    int l = j + 1, r = n - 1; 
    while (l<r)
        swap(a, l++, r--);
    return true;
}


int main() {
    int n, *arr;
    std::cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    Print(arr, n);
    while (Permutation(arr, n)) {
        Print(arr, n);
    }
    return 0;
}
