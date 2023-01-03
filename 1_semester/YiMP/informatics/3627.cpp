#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
 
    int N = 0;
    double X = 0, A = 0, Summa = 0;
    cin >> N >> X;
    cin >> A;
    do {
        Summa *= X;
        Summa += A;
        cin >> A;
    } while (N--);
    cout << Summa;
    return 0;
}