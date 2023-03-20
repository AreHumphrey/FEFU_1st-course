#include <iostream>
#include <math.h>
using namespace std;
float F(float x) {
    return 3. / 2 * sqrt(4 - x * x);
}
int main() {
  float x = -2;
  float b = 1.99;
  float h = 0.01;
  double L = 0;
  while( x < b ) {
    float y1 = F(x);
    float y2 = F(x+h);
    L += sqrt(h*h + (y2-y1)*(y2-y1));
    x += h;
  }
  cout << "Длина кривой " << fixed
  << setw(10) << setprecision(3) << L*2;
}
