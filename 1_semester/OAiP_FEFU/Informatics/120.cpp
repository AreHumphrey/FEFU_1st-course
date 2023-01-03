//Задача №120. 1/0!+1/1!+1/2!+...
//По данному натуральному числу N найдите сумму чисел 1+1/1!+1/2!+1/3!+...+1/N!. Количество действий должно быть пропорционально N.
#include <iomanip>
#include <iostream>
using namespace std;
double Factorial_Ch(int N) {
    if (N == 1 || N == 0) {
        return 1;
    }
    if (N == 2) {
        return 2;
    }
    else {
        return N * Factorial_Ch(N - 1);
    }

}

int main() {
    int N;
    cin >> N;
    double Rez_Dei = 1;


    for (double i = 1; i <= N; i++)
    {
        Rez_Dei += 1 / (Factorial_Ch(i));
    }

    cout << fixed<< setprecision(5) << Rez_Dei;
}
