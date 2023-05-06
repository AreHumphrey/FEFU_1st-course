#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


const int INF = std::numeric_limits<int>::max();

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    int s, t;
    std::cin >> s >> t;
    s--; 
    t--;
    std::vector<int> dist(n, INF);
    std::vector<int> path(n, -1);
    std::vector<bool> used(n);
    dist[s] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!used[j] && (v == -1 || dist[j] < dist[v])) {
                v = j;
            }
        }
        if (dist[v] == INF) {
            break;
        }
        used[v] = true;
        for (int u = 0; u < n; u++) {
            if (a[v][u] > 0) {
                int len = a[v][u];
                if (dist[v] + len < dist[u]) {
                    dist[u] = dist[v] + len;
                    path[u] = v;
                }
            }
        }
    }
    std::vector<int> ans;
    if (dist[t] == INF) {
        std::cout << "0" << std::endl;
        return 0;
    } else {
        int u = t;
        while (u != -1) {
            ans.push_back(u);
            u = path[u];
        }
        reverse(ans.begin(), ans.end());
    }
    std::cout << dist[t] << std::endl;
    for (int i: ans) {
        std::cout << i + 1 << " ";
    }
    std::cout << std::endl;
    return 0;
}
