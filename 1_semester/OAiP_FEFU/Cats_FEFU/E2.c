
struct SystemSoldier{
    float SoldierHeight;
    char SoldeirName[256];
};
struct SystemSoldier Arr[100000], ArrBuff[100000];
void MergeSort(struct SystemSoldier  Arr[], int l, int r)
{
    if (l == r) return;
    int mid = (l + r) / 2;
    MergeSort(Arr, l, mid);
    MergeSort(Arr, mid + 1, r);
    int i = l; int j = mid + 1;
    for (int step = 0; step < r - l + 1; step++)
    {
        if ((j > r) || ((i <= mid) && (Arr[i].SoldierHeight >= Arr[j].SoldierHeight)))
        {
            ArrBuff[step] = Arr[i];
            i++;
        }
        else{
            ArrBuff[step] = Arr[j];j++;}
    }
    for (int step = 0; step < r - l + 1; step++) Arr[l + step] = ArrBuff[step];
}
#include <stdio.h>
int main() {
    FILE *InPut = fopen("input.txt", "r"),
            *OutPut = fopen("output.txt", "w");
    int CountSoldier;
    fscanf(InPut, "%d", &CountSoldier);
    for (int i = 0; i < CountSoldier; i++){
        fscanf(InPut, "%f %s", &Arr[i].SoldierHeight, &Arr[i].SoldeirName);
    }
    MergeSort(Arr, 0, CountSoldier - 1);
    for (int i = 0; i < CountSoldier; i++){
        fprintf_s(OutPut, "%s\n", Arr[i].SoldeirName);
    }
}
