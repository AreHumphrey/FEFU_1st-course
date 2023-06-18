#include <iostream>
#include <algorithm>
#include <vector>
#include "task3.h"
const int MAXN = 1000;
int n;
int a[MAXN + 1][MAXN + 1];
int parent[MAXN + 1];
int pInt[MAXN + 1];
vector<pair<int, pair<int, int>>> edges;

void makeSet(int v) {
    parent[v] = v;
    pInt[v] = 0;
}

int findSet(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b) {
        if (pInt[a] < pInt[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (pInt[a] == pInt[b]) {
            pInt[a]++;
        }
    }
}

void kruskal() {
    for (int i = 1; i <= n; i++) {
        makeSet(i);
        for (int j = i + 1; j <= n; j++) {
            if (a[i][j] > 0) {
                edges.push_back(make_pair(a[i][j], make_pair(i, j)));
            }
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int w = edges[i].first;
        if (findSet(u) != findSet(v)) {
            unionSets(u, v);
            a[u][v] = a[v][u] = w;
        }
    }
}

void task3() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    kruskal();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] > 0) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
