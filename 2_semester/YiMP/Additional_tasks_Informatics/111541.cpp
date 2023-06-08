#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100;

int n;
int adj[MAXN][MAXN];

bool isTree() {
    int countEdges = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (adj[i][j] == 1) {
                countEdges++;
            }
        }
    }

    if (countEdges != n - 1) {
        return false;
    }

    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    if (isTree()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
