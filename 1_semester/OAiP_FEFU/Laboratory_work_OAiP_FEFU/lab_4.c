//___________________________________Задание №1______________________________
//Требуется подсчитать в исходной строке количество подстрок, которые начинаются с символа A и заканчиваются символом
// B (значения A и B задаются пользователем).
//Выходной файл должен содержать результат применения указанной операции к последовательности строк из входного файла.
#include <stdio.h>
#include <windows.h>
#include <time.h>

int main() {
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);
    FILE *FailOutWorkProj;
    FILE *FailOutLateEdishn;
    FILE *FailInAB;
    FailInAB = fopen("C://Users//lutdi//CLionProjects//lab_4//cmake-build-debug//Fail1", "r");
    FailOutWorkProj = fopen("outputwork_1.txt", "w");
    FailOutLateEdishn = fopen("output_1.txt", "w");
    char ElementStart;
    char ElementEnd;
    int CountElementInArrLetter, Identif = 2000987, TotalCount = 0;
    char *ArrLetter;
    printf("Введите количество элементов: ");
    scanf_s("%d", &CountElementInArrLetter);
    ArrLetter = (char *) malloc(sizeof(char) * CountElementInArrLetter);
    ElementStart = fgetc(FailInAB);
    ElementEnd = fgetc(FailInAB);
    // fscanf_s(FailInAB, "%c", &ElementStart);
    // fscanf_s(FailInAB, "%c", &ElementEnd); //Считываем из файла значения А и В (нвчало и конец предполагаемой подстроки)
    printf("START: %c, END: %c", ElementStart, ElementEnd);
    for (int i = 0; i < CountElementInArrLetter; i++) { //
        ArrLetter[i] = 65 + rand() % (26);
        fprintf(FailOutWorkProj, "%c",
                ArrLetter[i]); //заполняем массив сгенерированными символами и добавляем полученную строку в файл
    }
    for (int i = 0; i < CountElementInArrLetter; i++) {

        if (ArrLetter[i] == ElementStart) {
            Identif = i;
        }
        if (ArrLetter[i] == ElementEnd && Identif < i) {
            TotalCount += 1;
            Identif = 2000987;
        }
    }
    fprintf(FailOutLateEdishn, "%d", TotalCount);
    fclose(FailInAB);
    fclose(FailOutLateEdishn);
    fclose(FailOutWorkProj);
    free(ArrLetter);
}
//___________________________________Задание №2______________________________
//Строку, состоящую из одинаковых символов, будем называть «равномерной». Требуется
//подсчитать в исходной строке количество таких подстрок максимально возможной длины.
//Выходной файл должен содержать результат применения указанной операции к
//последовательности строк из входного файла.
//strlen()- длина строки string.h
//#include <stdio.h>
//#include <time.h>
//#include <windows.h>
//int main(){
//    srand(time(NULL));
//    SetConsoleOutputCP(CP_UTF8);
//    FILE *FailOutWorkProj; FILE * FailOutLateEdishn;
//    FailOutWorkProj = fopen("outputwork_2.txt", "w");
//    FailOutLateEdishn = fopen("output_2.txt", "w");
//    int CountElementInArrSymbol, MaxPovtoreniuSymbol = 1,SecondMaxPovtoreniuSymbol = 0, PovtorSymbol = 1, *CountMaxPovtoreniuSymbol; char *ArrSymbol;
//    printf("Введите необходимую длину строки: \n"); scanf_s("%d", &CountElementInArrSymbol);
//    ArrSymbol = (char*)malloc(sizeof(char)*CountElementInArrSymbol);
//    CountMaxPovtoreniuSymbol = (int*)malloc(sizeof(int)*CountElementInArrSymbol);
//    for (int i = 0; i < CountElementInArrSymbol; i++){
//        ArrSymbol[i] = 'A' + rand() % ('C' - 'A');
//        CountMaxPovtoreniuSymbol[i] = 0;
//        fprintf(FailOutWorkProj,"%c ", ArrSymbol[i]);  //Генерируем строку
//    }
//    for (int j = 0; j < CountElementInArrSymbol; j++){
//        if (ArrSymbol[j] == ArrSymbol[j + 1]){
//            PovtorSymbol += 1; //Если идущие символы равны то увеличиваем счетчик
//
//            MaxPovtoreniuSymbol = max(PovtorSymbol, MaxPovtoreniuSymbol); //находим максимум из текущей длины повторяющихся символов и максимальной их длиной
//            if (MaxPovtoreniuSymbol == PovtorSymbol){
//                CountMaxPovtoreniuSymbol[MaxPovtoreniuSymbol] += 1; //в список из длины повторений добавляем 1
//            }
//        } else {PovtorSymbol = 1;}
//    }
//    fprintf(FailOutLateEdishn, "//Максимальная длина:" "%d" "\n" "//Количество подстрок из одинаковых элементов этой длины:" "%d", MaxPovtoreniuSymbol, CountMaxPovtoreniuSymbol[MaxPovtoreniuSymbol]);
//    fclose(FailOutWorkProj); free(ArrSymbol); free(CountMaxPovtoreniuSymbol);
//
//}
//___________________________________Задание №3______________________________
//Пользователем задаются две строки одинаковой длины (A, B).
//При этом полагается, что строка A не должна содержать повторяющихся символов.
//Далее во входной строке S требуется заменить все символы, встречающиеся в строке A, на соответствующие символы строки B.
//Выходной файл должен содержать результат применения указанной операции к последовательности строк из входного файла.
//#include <stdio.h>
//#include <time.h>
//#include <windows.h>
//int check(char massive[],int CountArr, char chsl) {
//    int i = 0;
//    while (i != CountArr){
//        if (chsl==massive[i]){
//            return i;
//        }
//        i++;
//    }
//        return -1; //Фунция по поиску определенного элемента в массиве
//    }
//int main() {
//        srand(time(NULL));
//        SetConsoleOutputCP(CP_UTF8);
//        FILE *FailOutWorkProj;
//        FILE *FailOutLateEdishn;
//        int CountElementInArrAB, CountElementInArrS; char * ArrA; char *ArrB; char * ArrS; char RandomLetter = 0;
//        printf("Введите количество элементов: "); scanf_s("%d", &CountElementInArrAB);
//        FailOutWorkProj = fopen("outputwork_3.txt", "w");
//        FailOutLateEdishn = fopen("output_3.txt", "w");
//        printf("Введите количество элементов строки S: "); scanf_s(" %d", &CountElementInArrS);
//        ArrA = (char*)malloc(sizeof(char)*CountElementInArrAB);
//        ArrB = (char*)malloc(sizeof(char)*CountElementInArrAB);
//        ArrS = (char*)malloc(sizeof(char)*CountElementInArrS);
//        for (int i = 0; i < CountElementInArrAB; i++){ //Создаем строку А состоящую из уникальных элементов (неповторяющихся)
//            RandomLetter =  'A' + rand() % ('Z' - 'A');
//            for (int j =  0; j < CountElementInArrAB; j++){
//                if (RandomLetter == ArrA[j]){
//                    while (RandomLetter == ArrA[j]){
//                        RandomLetter = 'A' + rand() % ('Z' - 'A');}
//                    }
//                else {continue;} //Генерируем число до тех пор оно повторятся с уже существующими элементами строки
//            }
//            ArrA[i] = RandomLetter; //Выходим из цикла и присваиваем новое, уникальное число строке А
//            }
//        for (int i = 0; i < CountElementInArrAB; i++){
//            fprintf(FailOutWorkProj, "%c ", ArrA[i]); //Добавляем в файл строку А
//        }
//        fprintf(FailOutWorkProj, "\n");
//        for (int i = 0; i < CountElementInArrAB; i ++){
//            ArrB[i] = 'A' + rand() % ('Z' - 'A');
//            fprintf(FailOutWorkProj, "%c ", ArrB[i]); //Генерируем строку В и добавляем ее в файл
//            }
//        fprintf(FailOutWorkProj, "\n");
//            for (int i = 0; i < CountElementInArrS; i++){
//                ArrS[i] = 'A' + rand() % ('Z' - 'A');
//                fprintf(FailOutWorkProj, "%c ", ArrS[i]);
//                fprintf(FailOutLateEdishn, "%c ", ArrS[i]); //Генерируем строку S
//            }
//            fprintf(FailOutLateEdishn, "\n");
//            for (int i = 0; i < CountElementInArrS; i++){
//                if (check(ArrA, CountElementInArrAB, ArrS[i]) != -1) { //проверяем есть ли в строке А элемент массива S
//                    int IndexArrA = check(ArrA, CountElementInArrAB, ArrS[i]); //Если элемент есть присваиваем его индекс переменной
//                    ArrS[i] = ArrB[IndexArrA]; //Меняем элемент строки S на элемент в строке В, находящийся под тем же индесом
//                }
//            }
//            for (int i = 0;  i < CountElementInArrS; i++){
//                fprintf(FailOutLateEdishn, "%c ", ArrS[i]); //Выводим полученную строку S
//            }
//        fclose(FailOutWorkProj); fclose(FailOutLateEdishn); free(ArrS); free(ArrA); free(ArrB);
//}
//___________________________________Задание №4______________________________
//Пусть имеется строка символов S = {S1, S2, . . . , Sn}.
//Требуется определить суффикс наибольшей длины (отличный от самой строки), совпадающий с ее префиксом.
//Математическая постановка задачи сводится к поиску позиции , если такая существует, иначе .
//Выходной файл должен содержать все такие суффиксы для последовательности строк из входного файла.
//#include <stdio.h>
//#include <time.h>
//#include <windows.h>
//int main(){
//    srand(time(NULL));
//    SetConsoleOutputCP(CP_UTF8);
//    FILE *FailOutWorkProj;
//    FILE *FailOutLateEdishn;
//    FailOutWorkProj = fopen("outputwork_4.txt", "w");
//    FailOutLateEdishn = fopen("output_4.txt", "w");
//    int CountElementInArrS; char * ArrS;
//    printf("Введите количество элементов строки S: "); scanf_s(" %d", &CountElementInArrS);
//    ArrS = (char*)malloc(sizeof(char)*CountElementInArrS);
//    for (int i = 0; i < CountElementInArrS; i++){
//        ArrS[i] = 'A' + rand() % ('C' - 'A');
//        fprintf(FailOutWorkProj, "%c ", ArrS[i]); //генерируем строку S
//    }
//    if (CountElementInArrS %  2 == 0){ //Если количество элементов строки четно, то сравниваем первый и последний элемент, при этом идя в цикле до середины
//        for (int i = 0; i < (CountElementInArrS / 2); i++){
//            if (ArrS[i] == ArrS[CountElementInArrS - i - 1]){
//                fprintf(FailOutLateEdishn, "%c ", ArrS[i]);
//            }
//            else{ return 0;} //если цепочка из одинаковых элементов прерывается то выходим и цикла
//        }
//    }
//    else {
//        for (int i = 0; i < ((CountElementInArrS / 2) - 1); i++){ //Если число элементов нечетно то элемент находящийся в середине отбрасываем
//            if (ArrS[i] == ArrS[CountElementInArrS - i - 1]){
//                fprintf(FailOutLateEdishn, "%c ", ArrS[i]);
//            } else { return 0;} //аналогично четным
//        }
//    }
//    fclose(FailOutLateEdishn);fclose(FailOutWorkProj);free(ArrS);
//}
//___________________________________Задание №5______________________________
//Требуется выполнить разбиение исходной строки на подстроки фиксированной длины
//(задается пользователем), и произвести последовательную конкатенацию полученных
//подстрок, предварительно отсортировав их в лексикографическом порядке. Выходной
//файл должен содержать результат применения указанных операций к последовательности
//строк из входного файла.
//#include <stdio.h>
//#include <time.h>
//#include <windows.h>
//int main() {
//    srand(time(NULL));
//    SetConsoleOutputCP(CP_UTF8);
//    FILE *FailOutWorkProj;
//    FILE *FailOutLateEdishn;
//    FailOutWorkProj = fopen("outputwork_5.txt", "w");
//    FailOutLateEdishn = fopen("output_5.txt", "w");
//    char *ArrString; char * PodstString1; char* PodstString2; char IterableSym; int CountElementInArrString, DlinaPodstroki, IndexOfMIn = 1;
//    printf("Введите количество элементов массива: "); scanf_s("%d", &CountElementInArrString);
//    printf("Введите длину подстрок"); scanf_s("%d", &DlinaPodstroki);
//    ArrString = (char*)malloc(sizeof(char) * (CountElementInArrString + DlinaPodstroki/ DlinaPodstroki));
//    PodstString1 = (char*)malloc(sizeof(char)*CountElementInArrString);
//    PodstString2 = (char*)malloc(sizeof(char)*CountElementInArrString);
//    for (int i = 0; i < CountElementInArrString + CountElementInArrString / DlinaPodstroki + 1; i++){
//        ArrString[i] =  65 + rand() % 26;
//        fprintf(FailOutWorkProj, "%c", ArrString[i]);
//    }
//    for (int j = 0; j < CountElementInArrString / DlinaPodstroki; j++){
//        IterableSym = ArrString[1];
//        for (int i = DlinaPodstroki + 2; i < CountElementInArrString + DlinaPodstroki; i += DlinaPodstroki + 1){
//            if (IterableSym > ArrString[i]){
//                IterableSym = ArrString[i];
//                IndexOfMIn += 1;
//            }
//        }
//        for (int i = IndexOfMIn; i < IndexOfMIn + DlinaPodstroki; i++){
//            fprintf(FailOutLateEdishn, "%c", ArrString[i]);
//
//        }fprintf(FailOutLateEdishn, " ");
//        ArrString[IndexOfMIn] = (char)(91 + j);
//        IndexOfMIn += 1;
//    }
//
//
//
//}


//___________________________________Задание №6______________________________
//Исходная строка содержит последовательность слов, разделенных пробелами. Для
//каждого такого слова требуется выполнить операцию отражения. Выходной файл должен
//содержать результат применения указанных операций к последовательности строк из
//входного файла.
//#include <stdio.h>
//#include <time.h>
//#include <windows.h>
//int main() {
//    srand(time(NULL));
//    SetConsoleOutputCP(CP_UTF8);
//    FILE *FailOutWorkProj;
//    FILE *FailOutLateEdishn;
//    FailOutWorkProj = fopen("outputwork_6.txt", "w");
//    FailOutLateEdishn = fopen("output_6.txt", "w");
//    int CountElementInArrString, DlinaPodsroki;
//    char *ArrString;
//    printf("Введите количество элементов строки: ");
//    scanf_s(" %d", &CountElementInArrString);
//    printf("Какой длины должны быть слова: "); scanf_s("%d", &DlinaPodsroki);
//    ArrString = (char *) malloc(sizeof(char) * CountElementInArrString);
//    ArrString[0] = ' ';
//    for (int i = 1; i <= CountElementInArrString; i++) {
//        ArrString[i] = 'A' + rand() % ('S' - 'A');     //генерируем строку
//        fprintf(FailOutWorkProj, "%c", ArrString[i]);
//        if ((i % DlinaPodsroki == 0)) {fprintf(FailOutWorkProj, "\t"); }//разделяем строку на подстроки фиксированной длины
//    }
//    ArrString[0] = ' ';
//    int start = DlinaPodsroki;
//    for (int i = 1; i <= CountElementInArrString; i += DlinaPodsroki){ //
//        for (int j = start; j >= i; j--){   //Выводим элементы подстроки в обратном в обратном порядке
//            fprintf(FailOutLateEdishn, "%c", ArrString[j]);
//
//        }
//        fprintf(FailOutLateEdishn, "\t"); //полученную строку с отзеркаленными подстроками заново разделяем
//        start += DlinaPodsroki;
//    }
//    fclose(FailOutWorkProj); fclose(FailOutLateEdishn); free(ArrString);
//
//}
//___________________________________Задание №7______________________________
//Исходная строка, содержащая некоторое арифметическое выражение, состоит из набора
//целых чисел, знаков операций (’+’, ’-’, ’*’, ’/’) и круглых скобок. Требуется определить
//корректность их расстановки. Результат вывести в виде строки: ’RIGHT’ или ’WRONG’.
//Выходной файл должен содержать результат применения указанной операции к
//последовательности строк из входного файла.
//#include <stdio.h>
//#include <windows.h>
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//    FILE *FailOutWorkProj;
//    FILE *FailOutLateEdishn;
//    FailOutWorkProj = fopen("outputwork_7.txt", "w");
//    FailOutLateEdishn = fopen("output_7.txt", "w");
//    char *ArrString;
//    int CountElementInArrString, Flag_1 = 0, CountbracketOpen = 0, CountBracketClosed = 0; //количество элементов массива, проверка знака "-", количество ")"б количество "("
//    printf("Введите длину предполагаемого арифметического выражения: ");
//    printf("\n");
//    scanf_s("%d", &CountElementInArrString);
//    ArrString = (char *) malloc(sizeof(char) * CountElementInArrString);
//    printf("Введите выражение: ");
//    printf("\n");
//    for (int i = 0; i < CountElementInArrString + 2; i++) {
//        scanf_s("%c", &ArrString[i]);
//        fprintf(FailOutWorkProj, "%c", ArrString[i]); //Ввод выражения
//    }
//    for (int i = 0; i < CountElementInArrString + 2; i++) {
//        printf("%c ", ArrString[i]);
//    }
//    if (ArrString[0] == '-') { //Фиксируем разрешенный "-"
//        Flag_1 = 1;
//    }
//    if (ArrString[0] == '+' || ArrString[0] == '/' || ArrString[0] == '*' || ArrString[0] == ')') {//Проверка на отсутсвие арифметической операции в начале
//        fprintf(FailOutLateEdishn, "WRONG");
//        return 0;
//    }
//    for (int i = 0; i < CountElementInArrString; i++) { //Проверка отсутвия закрывающей скобки в начале выражения
//            if (ArrString[1] == ')') {
//                fprintf(FailOutLateEdishn, "WRONG");
//                return 0;
//            }
//            if ((ArrString[1] == '-' || ArrString[1] == '/' || ArrString[1] == '+' || ArrString[1] == '*') && //Если первым символом был - а вторым арифметическая операция
//                (Flag_1 == 1)) {
//                fprintf(FailOutLateEdishn, "WRONG");
//                return 0;
//            }
//            if (ArrString[0] == '(' && (ArrString[i] == '*' || ArrString[i] == '+' || ArrString[i] == '/')) { //Если первым символом была скобка то вторым не может быть арифметическая операция
//                fprintf(FailOutLateEdishn, "WRONG");
//            }
//            if (((ArrString[i] == '+' || ArrString[i] == '-' || ArrString[i] == '/' || ArrString[i] == '*') && //Проверка на отсутсвие идущих подряд арифметических операций
//                (ArrString[i + 1] == '+' || ArrString[i + 1] == '-' || ArrString[i + 1] == '/' ||
//                 ArrString[i + 1] == '*')) && !((ArrString[i] == '+' || ArrString[i] == '-' || ArrString[i] == '/' || ArrString[i] == '*') && ArrString[i + 1] == '(')) {
//                fprintf(FailOutLateEdishn, "WRONG");
//                return 0;
////            if ((ArrString[i] != '+' || ArrString[i] != '-' || ArrString[i] != '/' || ArrString[i] != '*') && ArrString[i] == '(')    {
////                fprintf(FailOutLateEdishn, "WRONG");
////                return 0;REI
////            }
//            }
//            if (ArrString[CountElementInArrString] == '-' || ArrString[CountElementInArrString] == '*' || ArrString[CountElementInArrString] == '/' || ArrString[CountElementInArrString] == '+' ||
//				ArrString[CountElementInArrString] == '(') {
//				fprintf(FailOutLateEdishn, "WRONG"); //Последним символом не может быть арифметичекая операция и открывающаяся скобка
//				return 0;
//			}
//            if (ArrString[i] == ')'){CountBracketClosed += 1;}
//            if (ArrString[i] == '('){CountbracketOpen += 1;}
////			for (int j = 0; j < CountElementInArrString; j++) { //Подсчет скобок в выражении
////				if (ArrString[j] == 41) {
////					CountBracketClosed += 1;
////				}
////				if (ArrString[j] == 40) {
////					CountbracketOpen += 1;
////				}
////			}
////			if ((ArrString[CountElementInArrString - i] != ')' && CountbracketOpen != CountBracketClosed) ||
////                (ArrString[CountElementInArrString - i]) == ')' && CountBracketClosed + 1  != CountbracketOpen) {
////                fprintf(FailOutLateEdishn, "WRONG");
////                return 0;
////            }
//
//        }
//    //Если последний элемент не является скобкой и при том количество скобок не четно (не равно друг другу)
//    //Если если последний элемент - ")" (при этом "(" он равнятся не может) и при прибавлении 1 к количеству скобок количество элементов не четно
//    if ((ArrString[CountElementInArrString] != ')' && CountbracketOpen != CountBracketClosed) ||
//        (ArrString[CountElementInArrString]) == ')' && CountBracketClosed + 1  != CountbracketOpen) {
//        fprintf(FailOutLateEdishn, "WRONG");
//        return 0;
//    }
//
//    // Если выражение прошло все описанные выше условия, то оно верно
//    fprintf(FailOutLateEdishn, "RIGHT");
//    free(ArrString); fclose(FailOutLateEdishn); fclose(FailOutWorkProj);
//
//}
////5(7-8)
//___________________________________Задание №8______________________________
//#include <stdio.h>
//
//int main() {
//
//    FILE* FailInPut = fopen("input8.txt", "r");
//    FILE* fout = fopen("output_8.txt", "w");
//
//    char ArrWordScan[100];
//    int OnlyNumbers = 1, IsErrorSimbol = 0;
//
//    while (!feof(FailInPut)) {
//
//        fgets(ArrWordScan, 100, FailInPut);
//
//        for (int i = 0; ArrWordScan[i] != 0; i++) {
//
//            if (ArrWordScan[i] != 10) { //если не перенос на следующую строку
//
//                if ((ArrWordScan[i] < 48) || (ArrWordScan[i] > 57 && ArrWordScan[i] < 65)
//                    || (ArrWordScan[i] > 90 && ArrWordScan[i] < 97 && ArrWordScan[i] != 95) || (ArrWordScan[i] > 122)) {
//                    IsErrorSimbol = 1;
//                }
//
//                if ((ArrWordScan[i] > 64 && ArrWordScan[i] < 91) || (ArrWordScan[i] > 96 && ArrWordScan[i] < 123)) {
//                    OnlyNumbers = 0;
//                }
//
//                if (((ArrWordScan[0] < 65) || (ArrWordScan[0] > 90 && ArrWordScan[0] < 97 && ArrWordScan[0] != 95) || (ArrWordScan[0] > 122)) && (OnlyNumbers == 0)) {
//                    IsErrorSimbol = 1;
//                }
//
//                if (ArrWordScan[0] == 95 && OnlyNumbers == 1) {
//                    OnlyNumbers = 0;
//                }
//
//                if ((ArrWordScan[0] == 'i' && ArrWordScan[1] == 'n' && ArrWordScan[2] == 't' && ArrWordScan[3] == 10) || /* int */
//
//                        (ArrWordScan[0] == 'c' && ArrWordScan[1] == 'h' && ArrWordScan[2] == 'a' && ArrWordScan[3] == 'r' && ArrWordScan[4] == 10) || /* char */
//                        /*--- --- --- --- ---*/
//                        (ArrWordScan[0] == 'f' && ArrWordScan[1] == 'l' && ArrWordScan[2] == 'o' && ArrWordScan[3] == 'a' && ArrWordScan[4] == 't' && ArrWordScan[4] == 10) || /* float */
//
//                        (ArrWordScan[0] == 'd' && ArrWordScan[1] == 'o' && ArrWordScan[2] == 'u' && ArrWordScan[3] == 'b' && ArrWordScan[4] == 'l' && ArrWordScan[4] == 'e' && ArrWordScan[5] == 10) || /* double */
//                        /*--- --- --- --- ---*/
//                        (ArrWordScan[0] == 'i' && ArrWordScan[1] == 'f' && ArrWordScan[2] == 10) || /* if */
//
//                        (ArrWordScan[0] == 'a' && ArrWordScan[1] == 'n' && ArrWordScan[2] == 'd' && ArrWordScan[3] == 10) || /* and */
//                        /*--- --- --- --- ---*/
//                        (ArrWordScan[0] == 'f' && ArrWordScan[1] == 'o' && ArrWordScan[2] == 'r' && ArrWordScan[3] == 10) || /* for */
//
//                        (ArrWordScan[0] == 'o' && ArrWordScan[1] == 'r' && ArrWordScan[2] == 10) || /* or */
//                        /*--- --- --- --- ---*/
//                        (ArrWordScan[0] == 'w' && ArrWordScan[1] == 'h' && ArrWordScan[2] == 'i' && ArrWordScan[3] == 'l' && ArrWordScan[4] == 'e' && ArrWordScan[4] == 10) || /* while */
//
//                        (ArrWordScan[0] == 'r' && ArrWordScan[1] == 'e' && ArrWordScan[2] == 't' && ArrWordScan[3] == 'u' && ArrWordScan[4] == 'r' && ArrWordScan[4] == 'n' && ArrWordScan[5] == 10)) { /* return */
//                    IsErrorSimbol = 1;
//                }
//            }
//        }
//
//        if (IsErrorSimbol == 0) {
//
//            if (OnlyNumbers == 1) { fprintf(fout, "CONST\n"); }
//            else { fprintf(fout, "IDENT\n"); }
//        }
//
//        else { fprintf(fout, "ERROR\n"); }
//
//        IsErrorSimbol = 0; OnlyNumbers = 1;
//    }
//}
//___________________________________Задание №9______________________________
//Входной текстовый файл содержит последовательность целых чисел, записанных римскими цифрами.
//В качестве разделителей используются пробелы. Требуется проверить корректность их написания.
//Выходной файл должен содержать числа из входного файла, записанные арабскими цифрами.
//#include <stdio.h>
//#include <windows.h>
//int main() {
//
//    FILE *FailWorkProj;
//    FILE *FailOutLateEdishn;
//    FailWorkProj = fopen("C://Users//lutdi//CLionProjects//lab_4//cmake-build-debug//Ex9_Lab4", "r");
//    FailOutLateEdishn = fopen("output_9.txt", "w");
//    char ArrRimski[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};//Максимальное количество символов в римской цифре: 9
//    int SummaArab = 0;
//    while (!feof(FailWorkProj)) {
//        fgets(ArrRimski, 9, FailWorkProj);
//        for (int i = 0; ArrRimski[i] != 0; i++) {
//            if (ArrRimski[i] != 10) { // проверяем конец ли строки
//                switch (ArrRimski[i]) {
//
//                    case 'M':
//                        SummaArab += 1000; //далее по принципу составления римских цифр добавляем или вычитаем (меньшие символы)
//                        break;
//                    case 'D':
//                        SummaArab += 500;
//                        break;
//                    case 'C':
//
//                        if (i + 1 < strlen(ArrRimski) && (ArrRimski[i + 1] == 'D' || ArrRimski[i + 1] == 'M'))
//                            SummaArab -= 100;
//                        else
//                            SummaArab += 100;
//                        break;
//                    case 'L':
//                        SummaArab += 50;
//                        break;
//                    case 'X':
//                        if (i + 1 < strlen(ArrRimski) &&
//                            (ArrRimski[i + 1] == 'L' || ArrRimski[i + 1] == 'C' || ArrRimski[i + 1] == 'M'))
//                            SummaArab -= 10;
//                        else
//                            SummaArab += 10;
//
//                        break;
//                    case 'V':
//                        SummaArab += 5;
//                        break;
//                    case 'I':
//                        if (i + 1 < strlen(ArrRimski) &&
//                            (ArrRimski[i + 1] == 'V' || ArrRimski[i + 1] == 'X' || ArrRimski[i + 1] == 'C'))
//                            SummaArab -= 1;
//                        else SummaArab += 1;
//
//                        break;
//
//                }
//            }
//
//        }
//        fprintf(FailOutLateEdishn, "%d\n", SummaArab);
//        printf("\n");
//        SummaArab = 0;
//    }
//    fclose(FailWorkProj);
//    fclose(FailOutLateEdishn);
//
//}


//___________________________________Задание №10______________________________
//Входной текстовый файл содержит последовательность десятичных чисел, по модулю
//не превосходящих (10^8 − 1). В качестве разделителей используются пробелы. Выходной
// файл должен содержать числа из входного файла, записанные в словесной форме (в
//соответствии с правилами русского языка).
//#include <stdio.h>
//#include <windows.h>
//int main() {
//    SetConsoleOutputCP(CP_UTF8);
//    FILE* FailOutWorkProj;
//    FILE* FailOutLateEdishn;
//    FailOutWorkProj = fopen("C://Users//lutdi//CLionProjects//lab_4//cmake-build-debug//CMakeListsLab4Ex10.txt", "r");
//    FailOutLateEdishn = fopen("output_10.txt", "w");
//
//    int ArrNumberScan[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//    int CountRazrudInNumber = 9;
//    int Number, d = 1, Len = 0;
//    while (!feof(FailOutWorkProj)) {
//
//        printf("\n");
//        d = 1;
//        Len = 0;
//        fscanf_s(FailOutWorkProj, "%d", &Number);
//        for (int i = 0; i < CountRazrudInNumber; i++) {
//            ArrNumberScan[CountRazrudInNumber - i - 1] = (Number / d) % 10;
//            d *= 10;
//            Len++;
//            if ((Number / d) == 0) {
//                break;
//            }
//        }
//        for (int i = CountRazrudInNumber-Len; i < CountRazrudInNumber; i++) {
//            printf("%d", ArrNumberScan[i]);
//        }
//        printf("\n");
//
//        if (ArrNumberScan[0] == 1){
//            fprintf(FailOutLateEdishn, "Сто миллионов");fprintf(FailOutLateEdishn, " ");
//        }
//
//        switch (ArrNumberScan[1]) {
//            case 1:
//                if (ArrNumberScan[2] == 0){
//            fprintf(FailOutLateEdishn, "Десять миллионов");fprintf(FailOutLateEdishn, " ");
//            }
//
//            if (ArrNumberScan[2] == 0){
//                case 2: fprintf(FailOutLateEdishn,"Двадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutWorkProj, "Тридцать");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Сорок");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пятьдесят");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шестьдесят");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семьдесят");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемьдесят");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девяносто");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }
//        if (ArrNumberScan[2] == 0 && ArrNumberScan[1] != 0){
//            fprintf(FailOutLateEdishn, "миллионов");
//            fprintf(FailOutLateEdishn, " ");
//            break;
//        }
//        if (ArrNumberScan[1] != 1){
//            switch (ArrNumberScan[2]) {
//                case 1: fprintf(FailOutLateEdishn, "Один миллион");fprintf(FailOutLateEdishn, " ");break;
//                case 2: fprintf(FailOutLateEdishn,"Два миллиона");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutLateEdishn, "Три миллиона");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Четыре миллиона");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пять миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шесть миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семь миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемь миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девять миллионов");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }
//        else{
//            switch (ArrNumberScan[2]) {
//                case 1: fprintf(FailOutLateEdishn, "Одиннадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 2: fprintf(FailOutLateEdishn, "Двенадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutLateEdishn, "Тринадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Четырнадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пятнадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шестьнадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семьнадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемьнадцать миллионов");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девятнадцать миллионов ");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }        //+++++++++++++++++++++++++++++++Миллионы+++++++++++++++++++++++++++++++++++++++++++
//        switch (ArrNumberScan[3]) {
//            case 1: fprintf(FailOutLateEdishn, "Сто"); fprintf(FailOutLateEdishn, " "); break;
//            case 2: fprintf(FailOutLateEdishn, "Двести"); fprintf(FailOutLateEdishn, " "); break;
//            case 3: fprintf(FailOutLateEdishn, "Триста"); fprintf(FailOutLateEdishn, " "); break;
//            case 4: fprintf(FailOutLateEdishn, "Четыреста"); fprintf(FailOutLateEdishn, " "); break;
//            case 5: fprintf(FailOutLateEdishn, "Пятьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 6: fprintf(FailOutLateEdishn, "Шестьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 7: fprintf(FailOutLateEdishn, "Семьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 8: fprintf(FailOutLateEdishn, "Восемьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 9: fprintf(FailOutLateEdishn, "Девятьсот"); fprintf(FailOutLateEdishn, " "); break;
//
//        }
//        switch (ArrNumberScan[4]) {
//            case 1:
//                if (ArrNumberScan[5] == 0){
//                    fprintf(FailOutLateEdishn, "Десять тысяч"); fprintf(FailOutLateEdishn, " "); break;
//                }
//                if (ArrNumberScan[5] == 0){
//                    case 2: fprintf(FailOutLateEdishn,"Двадцать");fprintf(FailOutLateEdishn, " "); break;
//                    case 3: fprintf(FailOutWorkProj, "Тридцать");fprintf(FailOutLateEdishn, " "); break;
//                    case 4: fprintf(FailOutLateEdishn, "Сорок");fprintf(FailOutLateEdishn, " "); break;
//                    case 5: fprintf(FailOutLateEdishn, "Пятьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 6: fprintf(FailOutLateEdishn, "Шестьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 7: fprintf(FailOutLateEdishn, "Семьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 8: fprintf(FailOutLateEdishn, "Восемьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 9: fprintf(FailOutLateEdishn, "Девяносто");fprintf(FailOutLateEdishn, " "); break;
//                }
//        }
//        if (ArrNumberScan[4] != 1){
//            if (ArrNumberScan[5] == 0 && (ArrNumberScan[3] != 0 || ArrNumberScan[4] != 0)){
//                fprintf(FailOutLateEdishn, "тысяч");
//            }
//
//            switch (ArrNumberScan[5]) {
//                case 1: fprintf(FailOutLateEdishn, "Одна тысяча");fprintf(FailOutLateEdishn, " ");break;
//                case 2: fprintf(FailOutLateEdishn,"Две тысячи");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutLateEdishn, "Три тысячи");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Четыре тысячи");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пять тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шесть тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семь тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемь тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девять тысяч");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }
//        else{
//            switch (ArrNumberScan[5]) {
//                case 1: fprintf(FailOutLateEdishn, "Одиннадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 2: fprintf(FailOutLateEdishn, "Двенадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutLateEdishn, "Тринадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Четырнадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пятнадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шестьнадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семьнадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемьнадцать тысяч");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девятнадцать тысяч ");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }//+++++++++++++++++++++++++++++++++++тысячи++++++++++++++++++++++++++++++++++++++++++++++++++
//        switch (ArrNumberScan[6]) {
//            case 1: fprintf(FailOutLateEdishn, "Сто"); fprintf(FailOutLateEdishn, " "); break;
//            case 2: fprintf(FailOutLateEdishn, "Двести"); fprintf(FailOutLateEdishn, " "); break;
//            case 3: fprintf(FailOutLateEdishn, "Триста"); fprintf(FailOutLateEdishn, " "); break;
//            case 4: fprintf(FailOutLateEdishn, "Четыреста"); fprintf(FailOutLateEdishn, " "); break;
//            case 5: fprintf(FailOutLateEdishn, "Пятьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 6: fprintf(FailOutLateEdishn, "Шестьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 7: fprintf(FailOutLateEdishn, "Семьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 8: fprintf(FailOutLateEdishn, "Восемьсот"); fprintf(FailOutLateEdishn, " "); break;
//            case 9: fprintf(FailOutLateEdishn, "Девятьсот"); fprintf(FailOutLateEdishn, " "); break;
//
//        }
//        switch (ArrNumberScan[7]) {
//            case 1:
//                if (ArrNumberScan[8] == 0){
//                    fprintf(FailOutLateEdishn, "Десять"); fprintf(FailOutLateEdishn, " ");break;
//                }
//                if (ArrNumberScan[8] == 0){
//                    case 2: fprintf(FailOutLateEdishn,"Двадцать");fprintf(FailOutLateEdishn, " "); break;
//                    case 3: fprintf(FailOutWorkProj, "Тридцать");fprintf(FailOutLateEdishn, " "); break;
//                    case 4: fprintf(FailOutLateEdishn, "Сорок");fprintf(FailOutLateEdishn, " "); break;
//                    case 5: fprintf(FailOutLateEdishn, "Пятьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 6: fprintf(FailOutLateEdishn, "Шестьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 7: fprintf(FailOutLateEdishn, "Семьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 8: fprintf(FailOutLateEdishn, "Восемьдесят");fprintf(FailOutLateEdishn, " "); break;
//                    case 9: fprintf(FailOutLateEdishn, "Девяносто");fprintf(FailOutLateEdishn, " "); break;
//                }
//        }
//        if (ArrNumberScan[7] != 1){
//            switch (ArrNumberScan[8]) {
//
//                case 1: fprintf(FailOutLateEdishn, "Один");fprintf(FailOutLateEdishn, " ");break;
//                case 2: fprintf(FailOutLateEdishn,"Два");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutLateEdishn, "Три");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Четыре");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пять");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шесть");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семь");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемь");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девять");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }
//        else{
//            switch (ArrNumberScan[8]) {
//                case 1: fprintf(FailOutLateEdishn, "Одиннадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 2: fprintf(FailOutLateEdishn, "Двенадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 3: fprintf(FailOutLateEdishn, "Тринадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 4: fprintf(FailOutLateEdishn, "Четырнадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 5: fprintf(FailOutLateEdishn, "Пятнадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 6: fprintf(FailOutLateEdishn, "Шестьнадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 7: fprintf(FailOutLateEdishn, "Семьнадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 8: fprintf(FailOutLateEdishn, "Восемьнадцать");fprintf(FailOutLateEdishn, " "); break;
//                case 9: fprintf(FailOutLateEdishn, "Девятнадцать ");fprintf(FailOutLateEdishn, " "); break;
//            }
//        }
//      fprintf(FailOutLateEdishn, "\n");
//    }
//    free(ArrNumberScan); fclose(FailOutLateEdishn);fclose(FailOutWorkProj);
//
//
//}
//
