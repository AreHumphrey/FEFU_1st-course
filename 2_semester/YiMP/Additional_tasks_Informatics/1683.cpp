#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

std::vector<std::vector<int>> g;
std::vector<int> used;
std::map<int, int> par;

int dfs(int v) {
    if (used[v])
        return 0;

    used[v] = 1;

    for (int u: g[v]) {
        if (par[u + 1] == 0 || dfs(par[u + 1] - 1)) {
            par[u + 1] = v + 1;
            return 1;
        }
    }

    return 0;
}

int main() {
    int n, s;
    std::cin >> n >> s;
    g.resize(n + s);
    for (int i = 0; i < s; i++) {
        for (int j = 0, now; j < n; j++) {
            std::cin >> now;

            if (now == 1) {
                g[i].push_back(s + j);
                g[s + j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n + s; i++) {
        used.clear();
        used.resize(n + s, 0);

        dfs(i);
    }

    int k = 0;

    for (auto _: par) {
        k += 1;
    }

    std::cout << k / 2;
}
