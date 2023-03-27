#include "graphics.h"
#pragma comment(lib,"graphics.lib")
//#include <conio.h>
#include <math.h>
#include <iostream>
int X0 = 400, Y0 = 450;
float Scale = 55 / 2;
float XMin = -5, XMax = 5, YMin = -5, YMax = 5;
int ScreenX(float x) {
    return int(X0 + 7 * Scale * x);
}
int ScreenY(float y) {
    return int(Y0 -  Scale * y);
}

void Axes(float Number) { 
    // Оси
    
    char s[10];
    setcolor(WHITE);
    //оси
    line(0, Y0, X0 * 2 - 1, Y0);
    line(X0, 0, X0, 799);

    // Стрелки

    
    int LeastIntX = (XMin);
    int LeastIntY = (YMin);
    // Стрелочки 
    line(X0, 0, ScreenX(Number / 2), Scale * Number);
    line(X0, 0, ScreenX(-Number / 2), Scale * Number);
    line(X0 * 2 - 1, Y0, X0 * 2 - Scale * Number, ScreenY(Number / 2));
    line(X0 * 2 - 1, Y0, X0 * 2 - Scale * Number, ScreenY(-Number / 2));

    for (int i = LeastIntX; i <= XMax; i++) {

        line(ScreenX(i), ScreenY(-Number / 2), ScreenX(i), ScreenY(Number / 2));
        // Отрисовка чисел 

        if (i != 0) {
            sprintf_s(s, "%d", i);
            outtextxy(ScreenX(i) - 4, ScreenY(-Number) + 3, s);
        }

        // Отрисовка линий

        for (float j = i + Number; j < i + 1 && j <= XMax; j += Number) {
            line(ScreenX(j), ScreenY(-Number / 4), ScreenX(j), ScreenY(Number / 4));

        }
    }
    // По Y
    for (int i = LeastIntY; i <= YMax; i++) {
        //отрисовка основных линий каждую единицу отрезка
        line(ScreenX(-Number / 2), ScreenY(i), ScreenX(Number / 2), ScreenY(i));

        //отрисовка чисел каждую единицу отрезка
        if (i != 0) {
            sprintf_s(s, "%d", i);
            outtextxy(ScreenX(Number) + 4, ScreenY(i) - 5, s);
        }

        //отрисовка дополнительных линий каждые 0.5 отрезка
        for (float j = i + Number; j < i + 1 && j < YMax; j += Number) {
            line(ScreenX(-Number / 4), ScreenY(j), ScreenX(Number / 4), ScreenY(j));
        }
    }
}

int main() {
   

  
    initwindow(X0 * 2, 800);
    Axes(0.5);


}
