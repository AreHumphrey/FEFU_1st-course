#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int main() {
	int K, N, CountStrok, LineNumberInPage;
	ifstream InFail("a.in");
	ofstream OutFail("a.out");
	InFail >> K >> N;

	if (N % K != 0) {
		LineNumberInPage = N / K + 1;
		CountStrok = N - (N / K) * K;
	}
	else {
		LineNumberInPage = N / K;
		CountStrok = K;
	}
	OutFail << LineNumberInPage << " " << CountStrok;
	InFail.close(); OutFail.close();
}