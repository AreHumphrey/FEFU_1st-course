#include <stdio.h>
struct ObgectCard {
    long long int Number;
    int Count;
};
int NumbersBuff[100000], ArrBuff[100000];
struct ObgectCard Numbers[100000], NumbersTwo[100000];
//void QuickSort(int *numbers, int left, int right);
void mergesort(int * a, int l, int r);
long long int LessThan(struct ObgectCard Arr[], int Size, long long int Key); //Функция поиска индекса;
int main() {
    FILE * InPut = fopen("game.in", "r"),
            * OutPut = fopen("game.out", "w");
    int n, k, SizeNumbers;
    long long int AnswerOfTast = 0;

    fscanf(InPut, "%d", &n);
    fscanf(InPut, "%d", &k);
    for (int i = 0; i < n; i++) {
        fscanf(InPut, "%d", &NumbersBuff[i]);
    }
    //Сортируем массив карточек по возастанию (с помощью быстрой сортировки)
    mergesort(NumbersBuff, 0, n - 1);
    Numbers[0].Number = NumbersBuff[0];
    Numbers[0].Count = 1;
    SizeNumbers = 1;
    //Группируем карточки по количеству
    for (int i = 1; i < n; i++) {
        if (NumbersBuff[i] == Numbers[SizeNumbers - 1].Number) {
            Numbers[SizeNumbers - 1].Count++;
        }
        else {
            SizeNumbers++;
            Numbers[SizeNumbers - 1].Number = NumbersBuff[i];
            Numbers[SizeNumbers - 1].Count = 1;
        }
    }
    //Проверяем на три одинаковые карточки и параллельно создаем массив карточек, колличество которых >= 2
    int SizeNumbersTwo = 0;
    for (int i = 0; i < SizeNumbers; i++) {
        if (Numbers[i].Count > 2) {
            AnswerOfTast++;
        }
        if (Numbers[i].Count > 1) {
            NumbersTwo[SizeNumbersTwo] = Numbers[i];
            SizeNumbersTwo++;
        }
    }
    //смотрим варианты a:b:b где b не больше а более чем в k раз
    //функция LessThan возвращает индекс минимального элемента большего чем key
    for (int i = 0; i < SizeNumbers; i++) {
        long long int top = LessThan(NumbersTwo, SizeNumbersTwo, Numbers[i].Number * k);
        long long int bottom = LessThan(NumbersTwo, SizeNumbersTwo, Numbers[i].Number);
        AnswerOfTast += 3 * (top - bottom);
    }
    //Рассматриваем варианты a:b:b где b не меньше, а более чем в k раз
    for (int i = 0; i < SizeNumbersTwo; i++) {
        long long int top = LessThan(Numbers, SizeNumbers, NumbersTwo[i].Number * k);
        long long int bottom = LessThan(Numbers, SizeNumbers, NumbersTwo[i].Number);
        AnswerOfTast += 3 * (top - bottom);
    }
    //случай где a:b:c (все различны)
    for (int i = 0; i < SizeNumbers; i++) {
        long long int top = LessThan(Numbers, SizeNumbers, Numbers[i].Number * k);
        long long int bottom = LessThan(Numbers, SizeNumbers, Numbers[i].Number);
        long long int len = top - bottom;
        AnswerOfTast += 6 * len * (len - 1) / 2;
    }
    fprintf(OutPut, "%lld", AnswerOfTast);
    fclose(InPut);
    fclose(OutPut);
    return 0;
}
//Изначально использовала быструю сортировку, но не прошло по времени в 57 тестах из 57, поэтому воспользуюсь сортировкой слияниями
void mergesort(int mas[], int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    mergesort(mas, l, m);
    mergesort(mas, m + 1, r);
    int i = l;
    int j = m + 1;
    for (int k = 0; k <= r - l; k++) {
        if (((i <= m) && (mas[i] <= mas[j])) || (j > r)) {
            ArrBuff[k] = mas[i];
            i++;
        }
        else {
            ArrBuff[k] = mas[j];
            j++;
        }
    }
    for (int k = 0; k <= r - l; k++) mas[l + k] = ArrBuff[k];
}
long long LessThan(struct ObgectCard Arr[], int Size, long long int Key) {
    long long l = 0;
    long long r = Size - 1;
    long long m = (r + l) / 2;
    while (l <= r) {
        if (Arr[m].Number == Key) return m + 1;
        else if (Arr[m].Number > Key) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
        m = (l + r) / 2;
    }
    if (Arr[m].Number > Key) return m;
    else return m + 1;
}
