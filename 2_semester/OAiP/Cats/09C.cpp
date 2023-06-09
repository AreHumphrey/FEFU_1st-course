#include <fstream>
#include <vector>
#include <queue>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n, m;
    input >> n >> m;
    std::vector<std::vector<int>> graph(n + 1);
    std::vector<int> inDegree(n + 1, 0);
    std::queue<int> q;
    std::vector<int> result;

    for (int i = 0; i < m; i++) {
        int a, b;
        input >> a >> b;
        graph[a].emplace_back(b);
        inDegree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        result.emplace_back(v);
        for (int u: graph[v]) {
            inDegree[u]--;
            if (inDegree[u] == 0) {
                q.push(u);
            }
        }
    }
    if (result.size() != n) {
        output << -1;
    } else {
        for (int v: result) {
            output << v << " ";
        }
        output << std::endl;
    }

    return 0;
}
