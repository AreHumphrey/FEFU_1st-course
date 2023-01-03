#include <iostream>
#include <math.h>
using namespace std;
int main() {
    double a, b, c, x, x1, x2;
    double Descrimenant = 0;
    cin >> a >> b >> c;
    Descrimenant = pow(b, 2) - 4 * a * c;
    if (Descrimenant == 0){
        x = -b / (2 * a);
        cout << x << endl;
    }
    if (Descrimenant > 0){
        x1 = (-b + pow(Descrimenant, 0.5)) / (2 * a);
        x2 = (-b - pow(Descrimenant, 0.5)) / (2 * a);
        cout << x1 << " " <<  x2 << endl;
    }
    return  0;

}
