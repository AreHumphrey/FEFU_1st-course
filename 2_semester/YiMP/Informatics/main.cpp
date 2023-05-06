#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }
    std::vector<bool> visited(n, false);
    visited[0] = true;
    std::vector<int> stack = {0};
    while (!stack.empty()) {
        int node = stack.back();
        stack.pop_back();
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                stack.push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    std::cout << "YES" << std::endl;

    return 0;
}
