#include "task1.h"
#include <iostream>
#include <windows.h>

int adjacencyMatrix[50][50], top[50], out[50][2];

int NumberSearch(int size) {
    int count1, count2, id = 0;
    for (count1 = 0; count1 < size; count1++) {
        for (count2 = 0; count2 < size; count2++) {
            if (adjacencyMatrix[count1][count2]) {
                out[count1][0] += 1;
            }
            if (adjacencyMatrix[count2][count1]) {
                out[count1][1] += 1;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        if (out[i][0] != out[i][1]) {
            id += 1;
        }
    }
    if (!id) {
        return 0;
    } else {
        return 1;
    }
}

void task1() {
    SetConsoleOutputCP(CP_UTF8);
    int vertexes, edges;
    int count1, count2;
    std::cout << "Введите количество вершин" << std::endl;
    std::cin >> vertexes;
    std::cout << std::endl;
    std::cout << "Введите количество ребер:" << std::endl;
    std::cin >> edges;
    for (int i = 0; i < edges; i++) {
        std::cin >> count1 >> count2;
        adjacencyMatrix[count1][count2] = 1;
    }
    if (!NumberSearch(vertexes)) {
        std::cout << "Эйлеров цикл есть" << std::endl;
    } else {
        std::cout << "Эйлерова цикла нет" << std::endl;
    }


}