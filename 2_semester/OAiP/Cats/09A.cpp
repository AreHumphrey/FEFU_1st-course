#include <fstream>
#include <vector>

std::vector<std::vector<int>> graph;
std::vector<bool> visited;
int n, m;

bool dfs(int v, int parent) {
    visited[v] = true;
    for (int u: graph[v]) {
        if (!visited[u]) {
            if (dfs(u, v)) {
                return true;
            }
        } else if (u != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        input >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    bool isTree = true;
    int cntConnected = 0;
    int cntEdges = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cntConnected++;
            if (cntConnected > 1 || (cntEdges > 0 && cntConnected == 1)) {
                isTree = false;
                break;
            }
            if (dfs(i, -1)) {
                isTree = false;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cntEdges += graph[i].size();
    }
    if (isTree && cntEdges == 2 * (n - 1)) {
        output << "YES";
    } else {
        output << "NO";
    }

    return 0;
}
