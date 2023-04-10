#include "graphics.h"
#pragma comment(lib,"graphics.lib")
#include <math.h>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

int X0 = 400, Y0 = 450;
float Scale = 55 / 2;
// Предел разметки по осям
float XMin = -5, XMax = 5, YMin = -10, YMax = 16;
float lims[4] = { -5, 5, -13, 16 };
// По X
int ScreenX(float x) {
    return int(X0 + 2 * Scale * x);
}
//По Y
int ScreenY(float y) {
    return int(Y0 - Scale * y);
}

//отрисовка осей
void axes(float Number)
{
    //оси X0 * 2 - 1
    line(0, Y0, X0 * 2 - 1, Y0);
    line(X0, 0, X0, 799);

    // Стрелки
    line(X0, 0, ScreenX(Number / 2), Scale * Number);
    line(X0, 0, ScreenX(-Number / 2), Scale * Number);
    line(X0 * 2 - 1, Y0, X0 * 2 - Scale * Number, ScreenY(Number / 2));
    line(X0 * 2 - 1, Y0, X0 * 2 - Scale * Number, ScreenY(-Number / 2));

    char s[10];
    int MinimumX = floor(XMin);
    int MinimumY = floor(YMin);

    // По х
    for (int i = MinimumX; i <= XMax; i++) {
        // Отрисовывание линий 
        line(ScreenX(i), ScreenY(-Number / 2), ScreenX(i), ScreenY(Number / 2));

        //Отрисовывание дополнительных линий
        for (float j = i + Number; j < i + 1 && j < XMax; j += Number) {
            line(ScreenX(j), ScreenY(-Number / 4), ScreenX(j), ScreenY(Number / 4));
        }

        // Отрисовывание чисел
        if (i != 0) {
            sprintf_s(s, "%d", i);
            outtextxy(ScreenX(i) - 4, ScreenY(-Number) + 3, s);
        }
    }

    //По y
    for (int i = MinimumY; i <= YMax; i++) {
        // Отрисовывание линий
        line(ScreenX(-Number / 2), ScreenY(i), ScreenX(Number / 2), ScreenY(i));

        //Отрисовывание дополнительных линий
        for (float j = i + Number; j < i + 1 && j < YMax; j += Number) {
            line(ScreenX(-Number / 4), ScreenY(j), ScreenX(Number / 4), ScreenY(j));
        }

        // Отрисовывание чисел
        if (i != 0) {
            sprintf_s(s, "%d", i);
            outtextxy(ScreenX(Number) + 4, ScreenY(i) - 5, s);
        }


    }
}

// Данная Функция
float F1(float x) {
    return pow(x, 3) + 2 * pow(x, 2) - 2 * x + 1;
}

float F2(float x) {
    return -12 * sin(x) + 1 * cos(x);
}
// Построение графика функции
void Plot(float Func(float), float Boundaries, int color) {
    int MinimumX = floor(XMin);
    int MaximumX = floor(XMax);
    float X;
    float Y, Y2;
    float H = (XMax - XMin) / Boundaries;
    setcolor(color);
    for (X = XMin; X < XMax; X += H) {
        Y = Func(X);
        Y2 = Func(X + H);
        // Проверка на точку в диапазоне экрана
        if (YMin <= Y && Y <= YMax && YMin <= Y2 && Y2 <= YMax) {
            line(ScreenX(X), ScreenY(Y), ScreenX(X + H), ScreenY(Y2));
        }

    }
    setcolor(WHITE);


}

// Нахождение точки пересечения 
void IntersectPoint(vector<float>* inters_pts) {
    int xmin = lims[0], xmax = lims[1];

    float eps = 0.001;
    float delta = 2 * eps;

    float x = xmin;

    //ищем решение уравнения f(x) = f1(x) - f2(x) методом перебора
    while (x <= xmax) {
        if ((F1(x) - F2(x)) * (F1(x + delta) - F2(x + delta)) < 0)
            (*inters_pts).push_back(x);
        x += delta;
    }
}

// Вывод точки пересечения
void PrintIntersect(float X, float Y, int Dx, int Dy) {
    char Text[20];
    // Вывод X
    sprintf_s(Text, "x =%.2f", X);
    outtextxy(ScreenX(X) + Dx, ScreenY(Y) + Dy - 15, Text);
    // Вывод Y
    sprintf_s(Text, "y =%.2f", Y);
    outtextxy(ScreenX(X) + Dx, ScreenY(Y) + Dy, Text);
}

//вывод точки пересечения
void print_point(float x, float y, int dx, int dy) {
    char text[20];

    //выводим x координату
    sprintf_s(text, "x=%.2f", x);
    outtextxy(ScreenX(x) + dx, ScreenY(y) + dy - 15, text);

    //выводим y координату
    sprintf_s(text, "y=%.2f", y);
    outtextxy(ScreenX(x) + dx, ScreenY(y) + dy, text);
}
// Заштриховывание 
void Hatching(float x1, float x2, float h) {
    float y1, y2;
    setcolor(LIGHTBLUE);

    //По x с шагом h
    for (float x = x1 + h; x < x2; x += h) {
        //Определение нижнюю и верхнюю функцию
        if (F1(x) > F2(x))
            y1 = F1(x), y2 = F2(x);
        else
            y1 = F2(x), y2 = F1(x);

        //Проверка на выход за графическое окно
        y1 = y1 > YMax ? YMax : y1;
        y2 = y2 < YMin ? YMin : y2;

        
        line(ScreenX(x), ScreenY(y1), ScreenX(x), ScreenY(y2));
    }

    setcolor(WHITE);
}


// С помощью метода прямоугольника вычисляем площадь
float Square(float x1, float x2)
{
    char text[20];
    float y1, y2, x, S = 0, h = 0.001;

    for (x = x1; x < x2; x += h) {
        //определеям нижнюю и верхнюю функцию
        if (F1(x) > F2(x))
            y1 = F1(x), y2 = F2(x);
        else
            y1 = F2(x), y2 = F1(x);

        //вычесление площади
        S += h * (y1 - y2);
    }

    return S;

}
void PrintSquare(float s, int dx, int dy, int i) {
    char text[20];

    sprintf_s(text, "S%d=%.2f", i, s);
    outtextxy(20 + dx, 10 + dy, text);
}
int main()
{
    //dx, dy - переменные масштабирования

    initwindow(X0 * 2, 700);


    axes(0.5);

    Plot(F1, 6000, LIGHTMAGENTA);
    Plot(F2, 6000, LIGHTCYAN);

    vector<float> Vct;
    IntersectPoint(&Vct);


    //Вывод точки пересечения
    for (int i = 0; i < Vct.size(); i++) {
        print_point(Vct[i], F1(Vct[i]), -70, 0);

    }

    //Проходимся в массиве точек пересечения до предпоследнего элемента включительно
    for (int i = 0; i < Vct.size() - 1; i++) {
        //шрихуем между двумя точками песечения
        Hatching(Vct[i], Vct[i + 1], 0.2);

        //Вывод площадь шрихованной области
        int dy = i * 20;
        PrintSquare(Square(Vct[i], Vct[i + 1]), 0, dy, i + 1);

    }
    getch();
    closegraph();
    return 0;

}
