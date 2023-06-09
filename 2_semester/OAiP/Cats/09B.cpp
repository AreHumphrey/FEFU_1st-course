#include <fstream>
#include <stack>
#include <vector>
#include <bitset>

const int MAXN = 100005;

int n, m;
std::vector<int> g[MAXN];
std::bitset<MAXN> used;

void dfs(int v) {
    std::stack<int> s;
    s.push(v);
    used[v] = true;
    while (!s.empty()) {
        int u = s.top();
        s.pop();
        for (int i = 0; i < g[u].size(); i++) {
            int to = g[u][i];
            if (!used[to]) {
                used[to] = true;
                s.push(to);
            }
        }
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    input >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        input >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cnt++;
            dfs(i);
        }
    }
    output << cnt << " ";
}
