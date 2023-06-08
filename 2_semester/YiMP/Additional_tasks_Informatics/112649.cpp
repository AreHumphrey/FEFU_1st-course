#include <iostream>
#include <vector>
#include <algorithm>
int n;
int g[1000][1000];
int tin[1000], low[1000];
int shag = 0;
std::vector<std::pair<int, int>> bridges;

void dfs(int v, int p) {
    tin[v] = ++shag;
    low[v] = shag;
    for (int u = 0; u < n; u++) {
        if (g[v][u] && u != p) {
            if (tin[u] == 0) {
                dfs(u, v);
                low[v] = std::min(low[v], low[u]);
                if (low[u] > tin[v]) {

                    bridges.push_back(std::make_pair(std::min(u, v), std::max(u, v)));
                }
            } else {

                low[v] = std::min(low[v], tin[u]);
            }
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        if (tin[i] == 0) {
            dfs(i, -1);
        }
    }
    sort(bridges.begin(), bridges.end());
    std::cout << bridges.size() << std::endl;
    for (int i = 0; i < bridges.size(); i++) {
        std::cout << bridges[i].first + 1 << " " << bridges[i].second + 1 << std::endl;
    }

    return 0;
}
