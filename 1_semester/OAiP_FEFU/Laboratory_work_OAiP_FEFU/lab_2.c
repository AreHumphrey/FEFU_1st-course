//Задание 1
//Введите одномерный целочисленный массив. Найдите наибольший нечетный элемент и наименьший четный элемент.
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
int main() {
	srand(time(NULL));
    int arr_a_count, min_arr_a = 1000000, max_arr_a = -1000000;
	setlocale(LC_ALL, "Rus");
	printf("Введите количество элементов массива:\n");
	scanf_s("%d", &arr_a_count);
	int* arr_a;
	arr_a = (int*)malloc(sizeof(int) * arr_a_count);
	for (int i = 0; i < arr_a_count; i++)
	{
		arr_a[i] = rand() % 10000 + (-100);
	}
	for (int j = 0; j <= arr_a_count; j++)
	{
		printf("%d, ", arr_a[j]);
	}
	printf("\n");
	for (int i = 0; i < arr_a_count; i++) {
		if ((arr_a[i] < min_arr_a) && (arr_a[i] % 2 == 0)) {
			min_arr_a = arr_a[i];

		}
		if ((arr_a[i] > max_arr_a) && (arr_a[i] % 2 != 0)) {
			max_arr_a = arr_a[i];
		}
	}
	printf("Минимальный, четный элемент массива: %d\n", min_arr_a);
	printf("Максимальный, нечетный элемент массива: %d", max_arr_a);

 }
// Задание №2
//Найдите сумму отрицательных элементов массива.
//#include <stdio.h>
//#include <locale.h>
//#include <time.h>
//#include <stdlib.h>
//int main() {
//	srand(time(NULL));
//	int count_arr_b, summa_otr_ch_arr_b = 0;
//	int* arr_b;
//	setlocale(LC_ALL, "rus");
//	printf("Введите количество элементов массива\n");
//	scanf_s("%d", &count_arr_b);
//	arr_b = (int*)malloc(sizeof(int)* count_arr_b);
//	for (int i = 0; i <= count_arr_b; i++) {
//		arr_b[i] = rand() % 1000 + (-100);
//	}
//	for (int i = 0; i < count_arr_b; i++) {
//		printf("%d,", arr_b[i]);
//	}
//	printf("\n");
//	for (int j = 0; j <= count_arr_b; j++) {
//		if (arr_b[j] < 0) {
//			summa_otr_ch_arr_b += arr_b[j];
//		}
//	}
//	printf("Сумма отрицательных членов массива: %d", summa_otr_ch_arr_b);
//}

//Задание №3
//Найдите произведение элементов массива с нечетными номерами.
//#include <stdio.h>
//#include <time.h>
//#include <locale.h>
//#include <stdlib.h>
//int main() {
//	setlocale(LC_ALL, "rus");
//	srand(time(NULL));
//	int count_el_arr_mes, proizv_arr_mes_nech_elements = 1;
//	printf("Введите количество элеменов массива:\n");
//	scanf_s("%d", &count_el_arr_mes);
//	int* arr_mes;
//	arr_mes = (int*)malloc(sizeof(int) * count_el_arr_mes);
//	for (int i = 0; i <= count_el_arr_mes; i++) {
//		arr_mes[i] = rand() % 100;
//	}
//	for (int i = 0; i < count_el_arr_mes; i++) {
//		printf("%ld, ", arr_mes[i]);
//	}
//	printf("\n");
//	for (int j = 0; j < count_el_arr_mes; j ++) {
//		if (j % 2 != 0) {
//			proizv_arr_mes_nech_elements = arr_mes[j] * proizv_arr_mes_nech_elements;
//		}
//
//	}
//	printf("Произведение элементов под нечётными индексами равно:\n");
//	printf("%d", proizv_arr_mes_nech_elements);
//}
// Задание №4
//Найдите сумму элементов массива между двумя первыми нулями. Если двух нулей нет в массиве, то выведите ноль.
//#include <stdio.h>
//#include <locale.h>
//#include <time.h>
//#include <stdlib.h>
//int main() {
//	setlocale(LC_ALL, "RUS");
//	srand(time(NULL));
//	int* arr_mes_1;
//	int count_el_arr_mes_1, summa_arr_mes_near_zero = 0, ch_zero_index_1 = 66, ch_zero_index_2 = 66;
//	printf("Введите необходимое количество элементов массива:\n");
//	scanf_s("%d", &count_el_arr_mes_1);
//	arr_mes_1 = (int*)malloc(sizeof(int) * count_el_arr_mes_1);
//	for (int i = 0; i < count_el_arr_mes_1; i++)
//	{
//		arr_mes_1[i] = rand() % 10 + (-3);
//		printf("%d, ", arr_mes_1[i]);
//	}
//	printf("\n");
//
//	for (int j = 0; j < count_el_arr_mes_1; j++) {
//		if (arr_mes_1[j] == 0) {
//			if (ch_zero_index_1 == 66) {
//				ch_zero_index_1 = j;
//
//			}
//			else
//			{
//				ch_zero_index_2 = j;
//				break;
//			}
//		}
//	}
//	if (ch_zero_index_1 == 66 || ch_zero_index_2 == 66) {
//		printf("\n0\n");
//		return 0;
//	}
//	for (int j = ch_zero_index_1; j < ch_zero_index_2; j++) {
//			summa_arr_mes_near_zero += arr_mes_1[j];
//	}
//
//	printf("Результат работы: %d", summa_arr_mes_near_zero);
//
//}
// Задание №5
//
//Найдите наибольший и наименьший элемент массива.
//#include <stdio.h>
//#include <locale.h>
//#include <time.h>
//#include <stdlib.h>
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int* arr_massiv_ch;
//	int count_arr_massiv_ch, min_arr_massiv_ch = 1000000000, max_arr_massiv_ch = -1000000;
//	printf("Введите количество элементов массива:\n");
//	scanf_s("%d", &count_arr_massiv_ch);
//	arr_massiv_ch = (int*)malloc(sizeof(int) * count_arr_massiv_ch);
//	for (int i = 0; i < count_arr_massiv_ch; i++) {
//		arr_massiv_ch[i] = rand() % 1000 + (-100);
//	}
//	for (int i = 0; i < count_arr_massiv_ch; i++) {
//		printf("%d, ", arr_massiv_ch[i]);
//	}
//	printf("\n");
//	for (int j = 0; j < count_arr_massiv_ch; j++) {
//		if (arr_massiv_ch[j] > max_arr_massiv_ch) {
//			max_arr_massiv_ch = arr_massiv_ch[j];
//		}
//		if (arr_massiv_ch[j] < min_arr_massiv_ch) {
//			min_arr_massiv_ch = arr_massiv_ch[j];
//		}
//	}
//	printf("Максимальный элемент массива: %d", max_arr_massiv_ch);
//	printf("Минимальный элемент массива: %d", min_arr_massiv_ch);
//}

// Задание №6
//Найдите минимальный по модулю элемент массива.
//#include <stdio.h>
//#include <time.h>
//#include <locale.h>
//#include <stdlib.h>
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int* arr_1_6;
//	int count_arr_1_6, min_el_abs_arr_1_6 = 1000000000;
//	printf("Введите количество элементов массива: \n");
//	scanf_s("%d", &count_arr_1_6);
//	arr_1_6 = (int*)malloc(sizeof(int) * count_arr_1_6);
//	for (int i = 0; i < count_arr_1_6; i++) {
//		arr_1_6[i] = rand() % 1000 + (-100);
//	}
//	for (int i = 0; i < count_arr_1_6; i++) {
//		printf("%d, ", arr_1_6[i]);
//	}
//	printf("\n");
//	for (int j = 0; j < count_arr_1_6; j++) {
//		if (abs(arr_1_6[j]) < min_el_abs_arr_1_6) {
//			min_el_abs_arr_1_6 = abs(arr_1_6[j]);
//		}
//	}
//	printf("Минимальный по модулю элемент массива: %d", min_el_abs_arr_1_6);
//}

//Задание № 7
//Преобразовать массив так, чтобы сначала шли нулевые элементы, а затем все остальные.
//#include <stdio.h>
//#include <locale.h>
//#include <stdlib.h>>
//#include <time.h>
//int main() {
//	setlocale(LC_ALL, "Rus");
//	srand(time(NULL));
//	int* arr_a;
//	int count_el_arr_a;
//	printf("Введите количестсво элементов массива: \n");
//	scanf_s("%d", &count_el_arr_a);
//	arr_a = (int*)malloc(sizeof(int) * count_el_arr_a);
//	for (int i = 0; i < count_el_arr_a; i++) {
//		arr_a[i] = rand() % 10 + 0;
//		printf("%d, ", arr_a[i]);
//	}
//	printf("\n");
//	for (int j = 0; j < count_el_arr_a; j++) {
//		if (arr_a[j] == 0) {
//			printf("%d, ", arr_a[j]);
//		}
//	}
//	for (int j = 0; j < count_el_arr_a; j++) {
//		if (arr_a[j] != 0) {
//			printf("%d, ", arr_a[j]);
//		}
//	}
//}
