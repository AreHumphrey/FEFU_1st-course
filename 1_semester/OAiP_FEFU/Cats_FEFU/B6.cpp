#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int NumberX, ReturnBitK, BitRezult;
	fstream InFail("input.txt");
	ofstream OutFail("output.txt");
	InFail >> NumberX;
	InFail >> ReturnBitK;
	if (ReturnBitK > 31) {
		OutFail << 0;
	}
	else {
		BitRezult = (NumberX >> ReturnBitK) & 1;
		OutFail << BitRezult;
	}
	
	InFail.close(); OutFail.close();
}
