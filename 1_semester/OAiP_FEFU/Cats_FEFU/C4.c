#include <stdio.h>
#include <math.h>
int main() {
    FILE* InPut = fopen("input.txt", "r"),
            * OutPut = fopen("output.txt", "w");
    float X1, X2, Y1, Y2, XP, YP;
    int Chek = 0, Flag = 1;
    fscanf(InPut, "%f %f %f %f", &X1, &Y1, &X2, &Y2);
    if ((X1 > 0) && (X1 < 9) && (X2 > 0) && (X2 < 9) && (Y1 > 0) && (Y1 < 9) && (Y2 > 0) && (Y2 < 9)) {
        Chek = (fabs(X1 - X2) == fabs(Y1 - Y2));//Условие: если пешки на одной прямой (а именно диагонали \ /)
        if ((Chek == 1) && ((fabs(X1 - X2) > 1) && (fabs(Y1 - Y2) > 1))) {//Проверка на диагональность пешек, расстояние больше единицы => можно поставить слона между ними
            if (((X1 < X2) && (Y1 > Y2)) || ((X1 > X2) && (Y1 < Y2))) { //проверка на наклон /
                fprintf(OutPut, "%d %d", (int)ceil((X1 + X2) / 2), (int)floor((Y1 + Y2) / 2)); //неидеальность шахматной доски => 2 подходящие точки
            }
            else {
                fprintf(OutPut, "%d %d", (int)ceil((X1 + X2) / 2), (int)ceil((Y1 + Y2) / 2));
            }
        }
        else if ((Chek == 1) && (fabs(X1 - X2) <= 1) && (fabs(Y1 - Y2) <= 1)) {
            fprintf(OutPut, "%d", 0);
        }
        else if (Chek == 0) { //если пешки не на одной прямой
            for (int i = 1; i <= 8; i++) { //Тупой переборный алгоритм
                for (int j = 1; j <= 8; j++) {

                    XP = i;
                    YP = j;
                    Chek = ((fabs(XP - X1)) == (fabs(YP - Y1))) && ((fabs(XP - X2)) == (fabs(YP - Y2)));
                    if (Chek == 1) {
                        fprintf(OutPut, "%d %d", (int)XP, (int)YP);
                        Flag = 0;
                        break;
                    }
                }
                if (Flag == 0) {
                    break;
                }
            }
            if (Flag == 1) {
                fprintf(OutPut, "%d", 0);
            }
        }
    }
    else {
        fprintf(OutPut, "%d", 0);
    }
}
