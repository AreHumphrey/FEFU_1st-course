#include <iostream>
#include <math.h>
using namespace std;
float F1(float x) {
    return x * x;
}
float F2(float  x){
    return 4 * cos(x);
}

int main() {
    float Step = 0.01,
            x = 0, S = 0;
    while (x <= 10) {
        S += F1(x) * Step - F2(x) * Step;
        x += Step;
    }
    cout << S * 2 << endl;
}