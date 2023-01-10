#include <iostream>
#include <fstream>
using namespace std;
int main() {
	int KudCh, CountKudCh = 0;
	ifstream InFail("input.txt");
	ofstream OutFail("output.txt");
	InFail >> KudCh;
	for (int i = 1; i < KudCh; i++) {
		int Chislo = i, PereverChislo = 0;
		while (Chislo > 0) {
			PereverChislo += Chislo % 10;
			PereverChislo *= 10;
			Chislo /= 10;}
		PereverChislo /= 10;
		if (PereverChislo + i == KudCh) {
			CountKudCh += 1;}
	}

	OutFail << CountKudCh;
	InFail.close();
}
