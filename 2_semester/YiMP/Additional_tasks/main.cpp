#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double F(double x){
    return pow(x, 3) + 2 * pow(x, 2) - 8 * x + 1  + 12 * sin(x) - 8* cos(x);
}

int main(){
    float y, x, a;
    float eps = 0.0001;
    float delta = 2 * eps;
    cin >> x >> y;
    a = x;
    while(x <= y){
        x += delta;
        if (x - a >= 0.5){
            a += 0.5;
        }
        if(F(x)*F(x+delta) < 0){
            cout << " ("<< a << " ; " << a + 0.5 <<")" << endl;
            cout << endl;
            cout << round((x + eps) * 1000) / 1000;
        }
    }
}
//#include <stdio.h>#include <math.h>
//double f(double x){
//    return pow(x ,3 ) + 2*pow(x ,2) - 8*x + 1 + 5*sin(x) - 12 * cos(x);}
//int main(){
//    double y;    double left, right;
//    double eps = 0.001;    double delta = 2 * eps;
//    double x = -5;    while(x <= 5){
//        if(f(x)*f(x+delta) < 0){            left = x;
//            right = x + delta;            y = (left + right) / 2;
//            printf("Diaposon %.3f ; %.3f\n", left, right);            printf("Root = %.3f\n", y + eps);
//        }        x += delta;
//    }}
//
