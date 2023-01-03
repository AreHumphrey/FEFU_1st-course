#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream InFail("C:/Users/lutdi/OneDrive/Документы/B1.txt");
	ofstream OutFail("output.txt");
	const int SIZE = 6; string arr[SIZE], Element;
	arr[0] = "*";
	cout << arr[0] << endl;
	for (int i = 1; i <= SIZE; i++) {
		InFail >> arr[i];
		cout << " " << arr[i] << endl;
	}
	

}
