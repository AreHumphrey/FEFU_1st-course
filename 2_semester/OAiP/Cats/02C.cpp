#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define DELIT -10001

std::vector<int> pid;

bool Comparison(int a, int b) {
    return pid[a] == pid[b] ? a > b : pid[a] > pid[b];
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, a, b;
    std::cin >> n >> m;
    pid.resize(n + m);
    std::priority_queue<int, std::vector<int>, decltype(&Comparison)> pq(Comparison);

    for (int i = 0; i < n; i++) {
        std::cin >> pid[i];
        pq.push(i);
    }

    for (int i = 0; i < m; i++) {
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        pid[n + i] = pid[a] + pid[b];
        pq.push(n + i);
        pid[a] = DELIT;
        pid[b] = DELIT;
    }

    for (int i = 0; i < n + m; i++) {
        if (pid[i] != DELIT){
            std::cout << pid[i] << ' ';
        }
    }

    return 0;
}
