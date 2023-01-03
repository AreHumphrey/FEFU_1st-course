// ______________________________________Задание №1___________________________________________________
//Для некоторого заданного целочисленного массива A требуется посчитать сумму всех положительных и произведение всех ненулевых его элементов.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int Count_Arr_A_El, Summa_Poloz_El_Arr_A = 0, Proiz_Nenul_El_Arr_A = 1;
    int* Arr_A;
    printf("Enter the required number of array elements: \n");
    scanf_s("%d", &Count_Arr_A_El);
    srand(time (NULL));
    Arr_A = (int*)malloc(sizeof(int) * Count_Arr_A_El);
    printf("Array Elements:  ");
    for (int i = 0; i < Count_Arr_A_El; i++) {
        Arr_A[i] = rand() % 100 + (-50);
        printf("%d, ", Arr_A[i]);
    }
    printf("\n");
    for (int i = 0; i < Count_Arr_A_El; i++) {
        if (Arr_A[i] > 0) {
            Summa_Poloz_El_Arr_A += Arr_A[i];
        }
        if (Arr_A[i] != 0) {
            Proiz_Nenul_El_Arr_A *= Arr_A[i];
        }
    }
    printf("The sum of all positive elements of the entered array: %d \n", Summa_Poloz_El_Arr_A);
    printf("Multiplication of non-zero elements of the entered array: %d \n", Proiz_Nenul_El_Arr_A);
    free(Arr_A);
}
//// ______________________________________Задание №2___________________________________________________
// Пусть имеется целочисленный массив A. Требуется проверить, является ли он упорядоченным.
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <locale.h>
//int main() {
// setlocale(LC_ALL, "Rus");
// srand(time(NULL));
// bool Pr_Vozr= false; bool Pr_Ub = false;
// int Count_El_Arr_A; int* Arr_A;
// printf("Введите необходимое количество элементов массива: ");
// scanf_s("%d", &Count_El_Arr_A);
// Arr_A = (int*)malloc(sizeof(int) * Count_El_Arr_A);
// for (int i = 0; i < Count_El_Arr_A; i++) {
// Arr_A[i] = rand() % 100 + (-30);
// printf("%d, ", Arr_A[i]);
//	}
// for (int j = 0; j < Count_El_Arr_A - 1; j++) {
// if (Arr_A[j] > Arr_A[j + 1]) {Pr_Ub = true;}
// else { Pr_Ub = false; break; }
//	}
//	for (int j = 0; j < Count_El_Arr_A - 1; j++) {
// if (Arr_A[j] < Arr_A[j + 1]) { Pr_Vozr = true; }
// else { Pr_Vozr = false; break; }
//	}
// if (Pr_Ub == true) { printf("Массив является упорядоченным по убыванию"); }
// if (Pr_Vozr == true) { printf("Массив является упорядоченным по возрастанию");}
// if ((Pr_Ub == false) && (Pr_Vozr == false)) { printf("Массив не является упорядоченным"); }
//
//}
// // ______________________________________Задание №3___________________________________________________
// Пусть имеется целочисленный массив A. Требуется по заданному целому b вывести тройку чисел (m,i_1,i_2), где m – число вхождений b в исходный массив, i_1=min{i∶ A_i=b} и i_2=max{i∶ A_i=b}.
// В случае, если значение b не встречается в исходном массиве — вывести соответствующее сообщение.
//#include <time.h>
//#include <stdlib.h>
//#include <locale>
//int main() {
// setlocale(LC_ALL, "Rus");
// srand(time(NULL));
// int* Arr_A; int Size_El_Arr_A, Count_El = 0, index_1 = 100, index_2 = 0, Element;
// printf("Введите количество элементов массива: "); scanf_s("%d", &Size_El_Arr_A);
// Arr_A = (int*)malloc(sizeof(int) * Size_El_Arr_A);
// for (int i = 0; i < Size_El_Arr_A; i++) {
// Arr_A[i] = rand() % 10 + (-10);
//		printf("%d, ", Arr_A[i]);
//	}
// printf("\n");
// printf("Введите элемент: "); scanf_s("%d", &Element);
// for (int i = 0; i < Size_El_Arr_A; i++) {
// if (Arr_A[i] == Element) {
// Count_El += 1;
// index_1 = (index_1 > i) ? i : index_1;
// index_2 = (index_2 < i) ? i : index_2;
//		}
//	}
//	printf("n");
//	if (Count_El > 0) {
//		printf("m = %d \n i1 = %d \n i2 = %d", Count_El, index_1, index_2);
//	}
//	else {
//		printf("Выбранный элемент отсутсвует в массиве;");
//	}
//}
// ____________________________________Задание №4___________________________________________________
// Пусть имеется целочисленный массив A. Требуется переместить все нулевые элементы (A_i=0) в конец массива, сохранив при этом порядок следования его ненулевых элементов.
// Задачу решить, используя не более одного оператора цикла.
// Для проверки результата необходимо вывести элементы преобразованного массива на терминал.
//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//
//int main() {
//	int Arr_A_1[10], Arr_A_2[] = { 0,0,0,0,0,0,0,0,0,0 }, count = 0;
//
//	srand(time(NULL));
//
//	for (int i = 0; i < 10; i++) {
//		Arr_A_1[i] = rand() % 6 - 5;
//
//		if (Arr_A_1[i] != 0) {
//			Arr_A_2[count] = Arr_A_1[i];
//
//			count++;
//		}
//	}
//
//	printf("%d\t-\t%d\n%d\t-\t%d\n%d\t-\t%d\n%d\t-\t%d\n%d\t-\t%d\n",
//		Arr_A_1[0], Arr_A_2[0], Arr_A_1[1], Arr_A_2[1], Arr_A_1[2], Arr_A_2[2], Arr_A_1[3], Arr_A_2[3], Arr_A_1[4], Arr_A_2[4]);
//
//	printf("%d\t-\t%d\n%d\t-\t%d\n%d\t-\t%d\n%d\t-\t%d\n%d\t-\t%d\n",
//		Arr_A_1[5], Arr_A_2[5], Arr_A_1[6], Arr_A_2[6], Arr_A_1[7], Arr_A_2[7], Arr_A_1[8], Arr_A_2[8], Arr_A_1[9], Arr_A_2[9]);
//
//}

// ____________________________________Задание №5___________________________________________________
// Для произвольного целочисленного массива A по заданному числу m требуется выполнить один из двух алгоритмов сортировки: (m=± 1) – сортировку пузырьком; (m=± 2) – сортировку выбором.
// При этом знак переменной m определяет порядок сортировки: (m>0) – по возрастанию; (m<0) – по убыванию.
// Для проверки результата необходимо вывести элементы отсортированного массива на терминал.
// swap - меняет элементы местами;
//Selection sort(сортировка выбором) – суть алгоритма заключается в проходе по массиву от начала до конца
//в поиске минимального элемента массива и перемещении его в начало.
//Сложность такого алгоритма O(n2).
//Bubble sort(сортировка пузырьком) – данный алгоритм меняет местами два соседних элемента,
//если первый элемент массива больше второго.Так происходит до тех пор, пока алгоритм не обменяет местами все неотсортированные элементы.
//Сложность данного алгоритма сортировки равна O(n ^ 2).
// Альтернатива swap в сортировке по выбору:
/*int temp = Arr_A[i];
Arr_A[i] = Arr_A[Min_In_Arr_A];
Arr_A[Min_In_Arr_A] = temp;*/

//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <time.h>
//#include <utility>
//using std::swap;
//
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int* Arr_A; int m, Count_El_Arr_A;
//	printf("Введите необходимое количество элементов массива: "); scanf_s("%d", &Count_El_Arr_A);
//	Arr_A = (int*)malloc(sizeof(int) * Count_El_Arr_A);
//	for (int i = 0; i < Count_El_Arr_A; i++) {
//		Arr_A[i] = rand() % 1000;
//		printf("%d ", Arr_A[i]);
//	}
//	printf("\n"); printf("Введите тип сортировки: \n -1: пузырьковая сортировка по убыванию; \n 1: пузырьковая сортировка по возрастанию; \n -2: сортировка выбором по убыванию; \n  2: сортировка выбором по возрастанию;\n");
//	scanf_s("%d", &m); printf("\n");
//	int Min_In_Arr_A;
//	while (true) {
//		switch (m) {
//		case (1):
//			for (int i = 0; i < Count_El_Arr_A; i++) {
//				bool Flag = true;
//				for (int j = 0; j < Count_El_Arr_A - (i + 1); j++) {
//					if (Arr_A[j] > Arr_A[j + 1]) {
//						Flag = false;
//						swap(Arr_A[j], Arr_A[j + 1]);
//					}
//				}
//				if (Flag ) {break;}
//			}
//		case (-1):
//			for (int i = 0; i < Count_El_Arr_A; i++) {
//				bool Flag = true;
//				for (int j = 0; j < Count_El_Arr_A - (i + 1); j++) {
//					if (Arr_A[j] < Arr_A[j + 1]) {
//						Flag = false;
//						swap(Arr_A[j + 1], Arr_A[j]);
//					}
//				}
//				if (Flag) { break; }
//			}
//		case (2):
//			for (int i = 0; i < Count_El_Arr_A - 1; i++) {
//				Min_In_Arr_A = i;
//				for (int j = i + 1; j < Count_El_Arr_A; j++) {
//					if (Arr_A[j] > Arr_A[Min_In_Arr_A]) {
//						Min_In_Arr_A = j;
//					}
//				}
//				if (Min_In_Arr_A != i) {swap(Arr_A[i], Arr_A[Min_In_Arr_A]);
//				}
//			}
//		case(-2):
//			for (int i = 0; i < Count_El_Arr_A - 1; i++) {
//				Min_In_Arr_A = i;
//				for (int j = i + 1; j < Count_El_Arr_A; j++) {
//					if (Arr_A[j] < Arr_A[Min_In_Arr_A]) {
//						Min_In_Arr_A = j;
//					}
//
//				}
//				if (Min_In_Arr_A != i) {swap(Arr_A[i], Arr_A[Min_In_Arr_A]);}
//			}
//	}
//		for (int i = 0; i < Count_El_Arr_A; i++) {
//			printf("%d, ", Arr_A[i]);
////		}
////		return 0;
////	}
////
////
////}
//// ______________________________________Задание №6___________________________________________________
// 	Для упорядоченного целочисленного массива требуется выполнить поиск некоторого заданного значения b по методу бисекции (двоичный поиск). В качестве ответа вывести индекс i для которого (A_i=b).
// В случае, если значение b не встречается в исходном массиве — вывести соответствующее сообщение.
//#include <stdio.h>
//#include <locale.h>
//#include <stdlib.h>
//int seach_binary(int arr[], int left, int right, int key, int size){
//	int midd = 0;
//	for (int i = 0; i <= size; i++){
//		midd = (left + right) / 2;
//		if (key < arr[midd]) {
//			right = midd - 1;
//		}
//		else if (key > arr[midd]) {
//			left = midd + 1;
//		}
//		else {
//			return midd;
//		}
//		if (left > right) { return -1; }
//	}
//}
//int main() {
//	setlocale(LC_ALL, "rus");
//	int* arr_a; int count_arr_a, chislo = 0, index = 0;
//	printf("введите количество элементов: "); scanf_s("%d", &count_arr_a);
//	arr_a = (int*)malloc(sizeof(int) * count_arr_a);
//	for (int i = 0; i < count_arr_a; i++) {
//		arr_a[i] = rand() % 1000 + (-100);
//		printf("%d, ", arr_a[i]);
//	}
//	printf("\n");
//	printf("введите любое число: "); scanf_s("%d", &chislo);
//	index = seach_binary(arr_a, 0, count_arr_a, chislo, count_arr_a);
//	if (index >= 0) {
//		printf("указанное число находится под индексом: %d", index);
//	}
//	else {
//		printf("числа нет");
//	}
//}

//
//// ______________________________________Задание №7___________________________________________________
// Для произвольного целочисленного массива A требуется выполнить операцию отражения (обращения), т.е. поменять местами элементы, находящиеся на равном расстоянии от его границ.
// Для проверки результата необходимо вывести элементы преобразованного массива на терминал.
//#include <stdio.h>
//#include <malloc.h>
//#include <stdlib.h>
//#include <time.h>
//#include <locale.h>
//#include <utility>
//using std::swap;
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int Count_El_Arr_A;
//	printf("Введите необходимое количество элементов массива: "); scanf_s("%d", &Count_El_Arr_A);
//	int* Arr_A;
//	printf("Изначальный вид массива: ");
//	Arr_A = (int*)malloc(sizeof(int) * Count_El_Arr_A);
//	for (int i = 0; i < Count_El_Arr_A; i++) {
//		Arr_A[i] = rand() % 100 + (-60);
//		printf("%d, ", Arr_A[i]);
//	}
//	printf("\n ");
//	for (int j = 0; j < (Count_El_Arr_A / 2); j++) {
//		swap(Arr_A[j], Arr_A[Count_El_Arr_A -  1 - j]);
//	}
//	printf("Измененный вид массива: ");
//	for (int i = 0; i < Count_El_Arr_A; i++) {
//		printf("%d, ", Arr_A[i]);
//	}
//
//
//}
// ______________________________________Задание №8___________________________________________________
// Требуется по заданным натуральным числам (a,q≥2) перевести число a в q-ичную систему счисления. Для хранения его цифр завести отдельный целочисленный массив.
// При этом храниться они должны в порядке убывания их позиций (т.е. от старших к младшим).
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//#include <time.h>
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int  Q_Stepen, Chislo;
//	printf("Введите число: "); scanf_s("%d", &Chislo); printf("\n"); printf("Введите систему счисления: "); scanf_s("%d", &Q_Stepen);
//	int Arr_SS[32] = {};
//	if (Q_Stepen >= 2) {
//		for (int i = 31; i > 0; i--) {
//			Arr_SS[i] = Chislo % Q_Stepen;
//			Chislo /= Q_Stepen;
//		}
//
//	}
//	else { printf("Не соответствует условию"); }
//	for (int i = 1; i < 32; i++) {
//		printf("%d", Arr_SS[i]);
//	}
//}
// ______________________________________Задание №9___________________________________________________
// «Палиндромом» называется число, символьная запись которого (в заданной системе счисления) одинаково читается в обоих направлениях.
// Требуется по заданным натуральным числам (a,b,q ≥ 2) найти все числа из диапазона от a до b, которые представляют собой палиндромы в системе счисления по основанию q.
//#include <stdio.h>
//#include <stdlib.h>
//#include <locale.h>
//
//int main() {
//	setlocale(LC_ALL, "Rus");
// int a, b, q, arr_size = 0, res, res2, condit = 1;
//
// printf("Введите начало, Конец, Систему счисления: \n");
// scanf_s("%d %d %d", &a, &b, &q); printf("\n");
//
// int* arr;
//
// for (int i = a; i <= b; i++) {
// res = res2 = i;
//
// while (res > 0) {
// res /= q; arr_size++;
//		}
//
// arr = (int*)malloc(sizeof(int) * arr_size);
//
// for (int i = arr_size; i > 0; i--) {
// arr[i] = res2 % q;
// res2 /= q;
//		}
//
// for (int l = 1; l <= (arr_size / 2); l++) {
// if (arr[l] != arr[arr_size + 1 - l]) {
// condit = 0;
//			}
//		}
//
// if (condit == 1) {
// printf("%d  ", i); for (int j = 1; j <= arr_size; j++) {  } printf("\n");
//		}
// condit = 1;
// arr_size = 0;
//	}
//}
// ______________________________________Задание №10__________________________________________________
// Требуется найти все простые числа, не превосходящие заданного m. Для решения задачи воспользоваться решетом Эратосфена.
//#include <stdio.h>
//#include <locale.h>
//#include <corecrt_malloc.h>
//int main() {
//	setlocale(LC_ALL, "Rus");
//	int Count_m;
//	printf("M = "); scanf_s("%d", &Count_m);
//	int* Arr_M; Arr_M = (int*)malloc(sizeof(int) * (Count_m));
//	for (int i = 0; i < Count_m; i++) {
//		Arr_M[i] = i;
//	}
//	Arr_M[1] = 0;
//	for (int u = 2; u < Count_m; u++) {
//		if (Arr_M[u] != 0) {
//			for (int j = u * u; j < Count_m; j += u) {
//				Arr_M[j] = 0;
//			}
//		}
//	}
//	for (int i = 0; i < Count_m; i++) {
//		if (Arr_M[i] != 0) {
//			printf("    %d\n", Arr_M[i]);
//		}
//	}
//}
