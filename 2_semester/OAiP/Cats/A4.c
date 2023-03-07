#include <stdio.h>
#include <stdlib.h>
void QuickSort(int *Numbers, int Left, int Right)
{
  int Pivot;
  int LeftHold = Left;
  int RHold = Right;
    Pivot = Numbers[Left];
  while (Left < Right){
    while ((Numbers[Right] >= Pivot) && (Left < Right))
      Right--;
    if (Left != Right){
        Numbers[Left] = Numbers[Right];
      Left++;
    }
    while ((Numbers[Left] <= Pivot) && (Left < Right))
      Left++;
    if (Left != Right){
        Numbers[Right] = Numbers[Left];
      Right--;
    }
  }
    Numbers[Left] = Pivot;
    Pivot = Left;
    Left = LeftHold;
    Right = RHold;
  if (Left < Pivot){
      QuickSort(Numbers, Left, Pivot - 1);
  }
  if (Right > Pivot) {
      QuickSort(Numbers, Pivot + 1, Right);
  }
}
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    int CountAircraft, TimeLimit, Result = 0;
    fscanf(InPut, "%d", &CountAircraft);
    fscanf(InPut, "%d", &TimeLimit);
    int * ArrMinutes = (int *)malloc(sizeof (int) * CountAircraft);
    for (size_t i = 0; i < CountAircraft; i++){
        fscanf(InPut, "%d", &ArrMinutes[i]);
    }
    QuickSort(ArrMinutes, 0, CountAircraft - 1);
    for (size_t i = 0; i < CountAircraft; i++){
        if (Result < ArrMinutes[i]){
            Result = ArrMinutes[i];
        }
        Result += TimeLimit;
    }
    fprintf(OutPut, "%d", Result);
    free(ArrMinutes);
    fclose(InPut); fclose(OutPut);
}
