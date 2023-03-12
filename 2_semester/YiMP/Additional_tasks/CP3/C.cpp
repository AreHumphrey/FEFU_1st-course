#include <iostream>
#include <math.h>
using namespace std;
float F(float x) {
    return 3. / 2 * sqrt(4 - x * x);
}
float Func() {
    float Step = 0.01,
            Len = 0, x = 0;
    while (x <= 2 and (x + Step) * (x + Step) < 4) {
        Len += sqrt((F(x + Step) - F(x)) * (F(x + Step) - F(x)) + (Step * Step));
        x += Step;
    }
    return Len * 4;
}
int main() {
    float Disk = Func();
    float Ram = M_PI * (15 - sqrt(99));
    cout << Disk << endl << Ram << endl;
    cout << (Ram - Disk) / Ram * 100 << "%";
}
