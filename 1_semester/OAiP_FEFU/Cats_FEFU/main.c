#include <stdio.h>
#include <math.h>
int main() {

 FILE * InPut = fopen("input.txt ", "r");
 FILE * OutPut = fopen("output.txt ", "w");

 long long X1, y1, x2, y2, xp, yp;
 fscanf(InPut, "%lld %lld %lld %lld %lld %lld", &X1, &y1, &x2, &y2, &xp, &yp);

 x2 -= X1; xp -= X1;
 y2 -= y1; yp -= y1;

	if ((x2 < 0) && (xp < 0)) {
    x2 = -x2;
    xp = -xp;
	}

	if ((y2 < 0) && (yp < 0)) {
    y2 = -y2;
    yp = -yp;
	}


	if ((0 == x2) && (x2 == y2) && (y2 == xp) && (xp == yp)) {
		fprintf(OutPut, "CENTER");
    return 0;
	}

	else if ((0 == y2) && (y2 == yp)) {
		if ((xp * 10) >= (x2 * 10) / 2) { xp = x2 - xp; } //Если у нас линия, причем горизонтальная , а не прямоугольник

		if ((xp * 100) >= (x2 * 100) / 4) {
      fprintf(OutPut, "CENTER"); return  0;
      }
		else {
      fprintf(OutPut, "CORNER"); return 0;
      }
	}

	else if ((0 == x2) && (x2 == xp)) {
		if ((yp * 10) >= (y2 * 10) / 2) { yp = y2 - yp; }

		if ((yp * 100) >= (y2 * 100) / 4) {
      fprintf(OutPut, "CENTER"); return  0;
      }
		else {
      fprintf(OutPut, "CORNER"); return 0;  //Если у нас линия, причем вертикальная, а не прямоугольник
      }
	}

	else {
		if ((xp * 10) >= (x2 * 10) / 2) { xp = x2 - xp; } // сведение к частному случаю
		if ((yp * 10) >= (y2 * 10) / 2) {
      yp = y2 - yp;
      }

		if ((xp * 100 * abs((int)x2)) >= ((x2 * x2 + y2 * y2 - 4 * y2 * yp) * 100 * abs(x2)) / (4 * x2)) { fprintf(OutPut, "CENTER"); }
		else { fprintf(OutPut, "CORNER"); }
	}

}
