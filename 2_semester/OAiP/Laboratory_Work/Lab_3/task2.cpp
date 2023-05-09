#include "task2.h"
#include <vector>
#include <queue>
#include <windows.h>
#include <iostream>

using namespace std;

const int INF = 1e9;

int vertexes;
vector<vector<pair<int, int>>> gVector;

vector<int> ShortestDistance(int s) {
    vector<int> d(vertexes, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Очередь с приоритетом
    pq.push({0, s});

    while (!pq.empty()) {
        auto [dist, v] = pq.top();
        pq.pop();
        if (d[v] < dist) {
            continue;
        }
        for (auto [to, w]: gVector[v]) {
            if (d[v] + w < d[to]) {
                d[to] = d[v] + w;
                pq.push({d[to], to});
            }
        }
    }

    return d;
}

int task2() {
    SetConsoleOutputCP(CP_UTF8);
    int edges;
    std::cin >> vertexes >> edges;
    gVector.resize(vertexes);
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        gVector[u].push_back({v, w});
        gVector[v].push_back({u, w});
    }
    int s, t;
    cin >> s >> t;
    vector<int> distance = ShortestDistance(s);
    cout << "Расстояние от вершины " << s << " до вершины " << t << " равно " << distance[t] << endl;
    return 0;
}