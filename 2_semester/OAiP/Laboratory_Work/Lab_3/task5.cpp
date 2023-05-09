#include "task5.h"
#include <iostream>
#include <vector>

int countEl;
std::vector<int> g[100001];
bool used[100001];
std::vector<int> comp;

void dfs(int v) {
    used[v] = true;
    comp.push_back(v);
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to]) {
            dfs(to);
        }
    }
}

void FindComs() {
    for (int i = 0; i < countEl; i++) {
        used[i] = false;
    }
    for (int i = 0; i < countEl; i++) {
        if (!used[i]) {
            comp.clear();
            dfs(i);
            std::cout << "Компоненты" << std::endl;
            for (int j = 0; j < comp.size(); j++) {
                std::cout << " " << comp[j] << " ";
            }
            std::cout << std::endl;
        }

    }
}

void task5() {
    int vertexes, edges;
    std::cin >> vertexes >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    countEl = vertexes;
    FindComs();

}

