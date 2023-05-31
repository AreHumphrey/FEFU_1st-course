#include <iostream>
#include <vector>


void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited) {
    visited[v] = true;
    for (int u = 0; u < graph.size(); ++u) {
        if (graph[v][u] == 1 && !visited[u]) {
            dfs(u, graph, visited);
        }
    }
}

int main() {
    int n, s;
    std::cin >> n >> s;

    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> graph[i][j];
        }
    }

    std::vector<bool> visited(n);
    dfs(s - 1, graph, visited);

    int count = 0;
    for (bool v : visited) {
        if (v) {
            ++count;
        }
    }

    std::cout << count << std::endl;

    return 0;
}
