#include <iostream>
using namespace std;
int main() {
	int CountArrN, Index= 1, j, i; int* ArrN;
	cin >> CountArrN;
	ArrN = (int*)malloc(sizeof(int) * CountArrN);
	ArrN[0] = 2;
	for (i = 3; i <= CountArrN; i+=2) {
		j = 3;
		while ((j * j <= i) && (i % j != 0)) {
			j += 2;
		}
		if (j * j > i) {
			ArrN[Index] = i;
			Index++;
		}
	}
	for (int k = 0; k < Index; k++) {
		cout << ArrN[k] << " ";
		
	}
}
