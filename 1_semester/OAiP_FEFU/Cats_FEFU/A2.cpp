#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream InFail("input.txt");
	ofstream OutFail("output.txt");
	int ChisloA1, CountShagInChisloA1 = 0;
	InFail >> ChisloA1;
	//Положительные А1
	if (ChisloA1 >= 0 && ChisloA1 <= 100) { //возьмем 1 = 1 - 100 = -99 (99) ==> 99 - 100 = -1 (1) последний шаг, так как 1 уже было в цепочке;  
		CountShagInChisloA1 = 2;//Возьмем отличное от 1 число, например, 99 = 99 - 100 = -1 (1) = 1 - 100 = -99 (99) последний шаг;
	}
	if (ChisloA1 > 100 && ChisloA1 % 100 == 0) { //К примеру 350 = 350 - 100 = 250 - 100 = 150 - 100 = 50 - 100 = -50 (50) = -100 = -150 было и под это условие не подходит (для 3-его условия)
		CountShagInChisloA1 = ChisloA1 / 100 + 1; //возьмем 100 = 100 - 100 = 0 - 100 = -100 (100) шаг 2 - последний: 100 / 100 + 1 = 2;
	}
	if (ChisloA1 % 100 != 0 && ChisloA1 > 100) {//Возбмем 150 = 150 - 100 = 50 - 100 = -50 (50) число уже было в цепочке; 3 шагa 150 / 100 + 2 = 3;
		CountShagInChisloA1 = ChisloA1 / 100 + 2; 
	}
	// Отрицательные А1
	if (ChisloA1 <= -1 && ChisloA1 >= -100) { //Возьмем -1 - 100 = -101 (101) - 100 = 1 - 100 = -99 (99) - 100 = -1
		CountShagInChisloA1 = 4; 
	}
	if (ChisloA1 < -100 && abs(ChisloA1) % 100 == 0) {
		CountShagInChisloA1 = abs(ChisloA1) / 100 + 3;//возьмем -200 = -200 - 100 = -300 (300) - 100 = 200 - 100 = 100 - 100 = 0 - 100 = -100 (100) - 100 = (-200) 5 шагов: 200 / 100 = 2 + 3 = 5
	}
	if (ChisloA1 < -100 && abs(ChisloA1) % 100 != 0) {
		CountShagInChisloA1 = abs(ChisloA1) / 100 + 4; //Исходя из принципа с положительными числами;
	}
	OutFail << CountShagInChisloA1;
	InFail.close(); OutFail.close();
}
