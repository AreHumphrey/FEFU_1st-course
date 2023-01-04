#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int MaxChisloFail = -2147483648, CountElementFail, ScanElement;
	ifstream InFail("input.txt");
	ofstream OutFail("output.txt");
	InFail >> CountElementFail;
	for (int i = 0; i < CountElementFail; i++) {
		InFail >> ScanElement;
		if (ScanElement > MaxChisloFail) {
			MaxChisloFail = ScanElement;
		}
	}
	OutFail << MaxChisloFail;
	//cout << MaxChisloFail;
	InFail.close();
}
