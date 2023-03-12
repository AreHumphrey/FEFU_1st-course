#include <stdlib.h>
#include <stdio.h>
struct SystemSoldier{
    float SoldierHeight;
    char SoldeirName[256];
};
struct SystemSoldier * ArrBuff;
long long _mergeSort(struct SystemSoldier arr[],  struct SystemSoldier ArrBuff[],  int left, int right);
long long merge(struct SystemSoldier arr[], struct SystemSoldier ArrBuff[],
          int left, int mid, int right);
long long mergeSort(struct SystemSoldier arr[], int array_size)
{
    ArrBuff = (struct ArrBuff* ) malloc(sizeof (struct SystemSoldier) * array_size);
    return _mergeSort(arr, ArrBuff,  0, array_size - 1);
}
long long _mergeSort(struct SystemSoldier arr[], struct SystemSoldier ArrBuff[],
               int left, int right)
{
    int mid;
    long long inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr,ArrBuff, left, mid);
        inv_count += _mergeSort(arr, ArrBuff, mid + 1, right);

        inv_count += merge(arr, ArrBuff, left, mid + 1, right);
    }
    return inv_count;
}
long long merge(struct SystemSoldier arr[],  struct SystemSoldier ArrBuff[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if ((arr[i].SoldierHeight >= arr[j].SoldierHeight))
        {
            ArrBuff[k++] = arr[i++];
        }
        else
        {
            ArrBuff[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }
    while (i <= mid - 1) {
        ArrBuff[k++] = arr[i++];
    }
    while (j <= right) {
        ArrBuff[k++] = arr[j++];
    }
    for (i = left; i <= right; i++){

        arr[i] = ArrBuff[i];
    }

    return inv_count;
}
int main() {

    FILE *InPut = fopen("input.txt", "r"),
            *OutPut = fopen("output.txt", "w");
    int CountSoldier;
    fscanf(InPut, "%d", &CountSoldier);
    struct SystemSoldier * Arr = (struct  Arr*)malloc((sizeof(struct SystemSoldier)) * CountSoldier);
    for (int i = 0; i < CountSoldier; i++){
        fscanf(InPut, "%f %s", &Arr[i].SoldierHeight, &Arr[i].SoldeirName);
    }

    long long ans = mergeSort(Arr, CountSoldier);
    fprintf(OutPut, "%lld", ans);
}
