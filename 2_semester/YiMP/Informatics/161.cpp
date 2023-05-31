#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

const int MAXN = 20;

int n;
int x1, y1, x2, y2;
int dist[MAXN + 1][MAXN + 1];
std::pair<int, int> pred[MAXN + 1][MAXN + 1];

const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

bool valid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

void bfs(int sx, int sy) {
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (valid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                pred[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

int main() {
    std::cin >> n >> x1 >> y1 >> x2 >> y2;
    memset(dist, -1, sizeof(dist));
    memset(pred, -1, sizeof(pred));

    bfs(x1, y1);
    std::cout << dist[x2][y2] << std::endl;
    std::vector<std::pair<int, int>> path;
    int x = x2, y = y2;
    while (x != -1 && y != -1) {
        path.push_back({x, y});
        auto [px, py] = pred[x][y];
        x = px;
        y = py;
    }
    for (int i =path.size() - 1; i >= 0; i--) {
        std::cout << path[i].first << " " << path[i].second << std::endl;
    }

    return 0;
}
