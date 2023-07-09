#include <fstream>
#include <vector>
#include <queue>

const int INF = 1e9;

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n, m, s;
    input >> n >> m >> s;

    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        input >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    std::vector<int> dist(n + 1, INF);
    dist[s] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) {
            continue;
        }

        for (auto [v, w]: adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            output << -1 << " ";
        } else {
            output << dist[i] << " ";
        }
    }

    return 0;
}
