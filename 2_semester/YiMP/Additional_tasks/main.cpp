#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

float F(float x) {
    return pow(x, 3) + 2 * pow(x, 2) - 8 * x + 1 + 12 * sin(x) - 8 * cos(x);
}
//Тесты : -4.495 -1.386 0.850
void DCH(float Left, float Right, float Eps) {

    float delta = 2 * Eps - 0.0001, Mid, left = Left, right = Right;
    bool cond = 0;
    if ((right - left) / 2 > delta) {
        while (right - left > delta) {
            Mid = (right + left - Eps / 5) / 2;
            if (F(right) * F(Mid) <= 0) left = Mid, cond = 0;
            else right = Mid, cond = 1;
        }
        if (F(right) * F(left) <= 0) {
            cout << fixed << setw(3) << setprecision(3) << " [" << left << "; " << right + Eps << "] ==> " << (left + right) / 2  << "\n";
            if (!cond) {
                DCH(left + Eps, 5, 0.001);
            }
            else {
                DCH(-5, right - Eps, 0.001);
            }
        }
    }
}

int main() {
    DCH(-5, 5, 0.0001);
}