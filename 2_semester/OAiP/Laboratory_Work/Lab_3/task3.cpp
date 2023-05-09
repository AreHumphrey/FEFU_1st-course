#include "task3.h"
#include <iostream>

const int MAXN = 100;

int n;
int a[MAXN][MAXN];
int b[MAXN][MAXN];

void floyd() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][k] + a[k][j] < a[i][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    b[i][j] = 1;
                }
            }
        }
    }
}

void task3() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
            if (a[i][j] != 0) {
                b[i][j] = 1;
            }
        }
    }
    floyd();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << b[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

//алгоритм Флойда-Уоршелла для поиска кратчайших путей между всеми парами вершин в графе