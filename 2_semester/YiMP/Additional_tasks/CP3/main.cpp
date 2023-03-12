#include <iostream>
#include <cmath>
using namespace std;
float F(float x) { 
    return x * x; 
}
int main() {
    float Step = 0.001, LenOfParabola = 0, x = 0;
    while (x <= 10) {
        LenOfParabola += sqrt((F(x + Step) - F(x)) * (F(x + Step) - F(x)) + (Step * Step));
        x += Step;
    }
    cout << LenOfParabola << endl;
}
