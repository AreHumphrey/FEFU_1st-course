#include <fstream>
#include <vector>

const int INF = 1e9;

int main() {
    std::ifstream input ("input.txt");
    std::ofstream output ("output.txt");
    int n, m, s;
    input >> n >> m >> s;

    std::vector<std::vector<std::pair<int, int>>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        input >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    std::vector<int> dist(n+1, INF);
    dist[s] = 0;

    for (int k = 1; k <= n-1; k++) {
        for (int u = 1; u <= n; u++) {
            for (auto [v, w] : adj[u]) {
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            output << " " << " ";
        }
        else {
            output << dist[i] << " ";
        }
    }

    return 0;
}
