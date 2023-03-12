#include <iostream>
#include <math.h>
using namespace std;
float S = 10, H = 2, g = 10, a = 0;
float F(float x) {
    float V0 = (S * S * g * cos(a)) / (S * sin(a) - H * cos(a));
    return x * sin(a) / cos(a) - x * x * g / V0 - H;
}
void Func(float Alfa) {
    a = M_PI * Alfa / 180;
    float Step = 0.01,
            Len = 0, x = 0;
    while (x <= S) {
        Len += sqrt((F(x + Step) - F(x)) * (F(x + Step) - F(x)) + (Step * Step));
        x += Step;
    }
    cout << Len << endl;
}
int main() {
    Func(35.5);
    Func(65.8);
}
