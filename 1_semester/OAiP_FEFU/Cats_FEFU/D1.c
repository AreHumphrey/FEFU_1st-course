


#include <stdio.h>
#include <math.h>

int main() {
    FILE *InPut = fopen("input.txt", "r");
    FILE *OutPut = fopen("output.txt", "w");

    double Xa, Ya, Xb, Yb, X0, Y0, Betta, Xna, Yna, Xnb, Ynb;

    fscanf(InPut, "%lf %lf", &Xa, &Ya);
    fscanf(InPut, "%lf %lf", &Xb, &Yb);
    fscanf(InPut, "%lf %lf", &X0, &Y0);
    fscanf(InPut, "%lf", &Betta);
    double Corner = M_PI * Betta / 180;
    Xna = cos(Corner) * (Xa - X0) - sin(Corner) * (Ya - Y0);
    Yna = sin(Corner) * (Xa - X0) + cos(Corner) * (Ya - Y0);
    Xnb = cos(Corner) * (Xb - X0) - sin(Corner) * (Yb - Y0);
    Ynb = sin(Corner) * (Xb - X0) + cos(Corner) * (Yb - Y0);

    fprintf(OutPut, "%.9f %.9f %.9f %.9f", Xna + X0, Yna + Y0, Xnb + X0, Ynb + Y0);
}
