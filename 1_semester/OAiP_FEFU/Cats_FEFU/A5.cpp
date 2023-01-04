#include <iostream>
#include <fstream>
using namespace std; // 0 - 59 = -59
int main() {
	fstream InFail("input.txt");
	ofstream OutFail("output.txt");
	int HoursNow, MinNow, InsCh = 24, InsMin = 00;
	InFail >> HoursNow;
	InFail >> MinNow;
	InsCh = (InsCh - HoursNow);
	InsMin -= MinNow;
	if (abs(InsMin) != InsMin) {
		InsCh -= 1;
		InsMin = (60 + InsMin) % 60;
	}
	OutFail << InsCh << " " << InsMin;
	InFail.close(); OutFail.close();

}
