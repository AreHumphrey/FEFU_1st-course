#include <iostream>
using namespace std;

float F(float x) {
    return x * x;
}

int main() {
    float Step = 0.01,
            x = 0, S = 0;

    while (x <= 10) {
        S += F(x) * Step;
        x += Step;
    }

    cout << S << endl;
}
