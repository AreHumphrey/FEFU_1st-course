#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() {
    FILE * InPut = fopen("input.txt", "r");
    FILE * OutPut = fopen("output.txt", "w");
    float N, NBuff;
    int K;
    float * Otv = (float *)malloc(sizeof (float ));
    fscanf(InPut, "%f", &N); //цена
    fscanf(InPut, "%d", &K);
    int SqrtN = floor(sqrt(N));
    int Flag = 0, SqrtBuff;
    while (SqrtN > 0){ //Перебираю корни и делаю его все меньше (пока это возможно)
        NBuff = N;
        NBuff = NBuff - SqrtN  * SqrtN; //Тут проверяю нет ли корня у деньги (N)
        Otv[0] = SqrtN; //Вообще в любом случае на 0 месте это корень с окугление вниз
        if (NBuff != 0){ //Дальше если у меня все же нет этого корня я смотрю на оставшееся после корня число
            for (int i = 1; i < K; i++){
                SqrtBuff = floor(sqrt(NBuff));
                NBuff = NBuff - SqrtBuff * SqrtBuff; //проворачиваю эту же замуту с этим числом
                Otv = (float *) realloc(Otv, sizeof(float ));
                Otv[i] = SqrtBuff;
                if (NBuff == 0){
                    K = i + 1;
                    Flag = 1;
                    break;
                }
            }
        }
        else{
            Flag = 1;
            K = 1;
        }
        SqrtN --;
        if (Flag == 1){
            break;
        }

    }
    if (Flag != 0){
        fprintf(OutPut,   "YES\n");
        for (int i = 0; i < K; i++){
            fprintf(OutPut, "%d ", (int)Otv[i]);
        }
    }
    if (Flag == 0){
        fprintf(OutPut,  "NO\n");
    }

}
