#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE* InPut = fopen("InPut.txt", "r");
    FILE* OutPut = fopen("OutPut.txt", "w");
    int N;
    fscanf(InPut, "%d", &N);

    int *ArrPollen;
    ArrPollen = (int*)malloc(sizeof (int)*N);
    for (int i = 0; i < N; ++i) {
        fscanf(InPut, "%d", &ArrPollen[i]);
    }

    int MaxSumma = 0, IndexL, IndexM, IndexR;
    for (int i = 0; i < N - 1; i++) {
        int R = i;
        int M = i;

        int MSumma = ArrPollen[i];
        int RSumma = 0;

        while (R < N) {
            if (RSumma > MSumma) {
                M++;
                MSumma += ArrPollen[M];
                RSumma -= ArrPollen[M];
            } else {
                R++;
                RSumma += ArrPollen[R];
            }
            if (MSumma == RSumma && MSumma > MaxSumma) {
                MaxSumma = MSumma;
                IndexL = i + 1;
                IndexM = M + 1;
                IndexR = R + 1;
            }

        }
    }

    if (MaxSumma != 0) {
        fprintf(OutPut,"%d %d %d", IndexL, IndexM, IndexR);
    } else {
        fprintf(OutPut, "%i", -1);
    }
}
