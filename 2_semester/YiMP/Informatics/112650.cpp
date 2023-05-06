#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int MAX_N = 1000;
int graph[MAX_N][MAX_N];
bool visited[MAX_N];

class Edge {
public:
    int from, to, weight;
    bool operator<(const Edge &other) const {
        return weight > other.weight;
    }
};

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> graph[i][j];
        }
    }

    std::fill(visited, visited + n, false);

    std::vector <Edge> edges;
    visited[0] = true;
    for (int i = 1; i < n; i++) {
        if (graph[0][i] != 0) {
            edges.push_back({0, i, graph[0][i]});
        }
    }

    std::priority_queue <Edge> pq;
    for (auto edge: edges) {
        pq.push(edge);
    }

    std::vector <std::pair<int, int>> mst;
    while (!pq.empty()) {
        auto current_edge = pq.top();
        pq.pop();

        if (visited[current_edge.from] && visited[current_edge.to]) {
            continue;
        }

        mst.push_back({std::min(current_edge.from, current_edge.to) + 1, std::max(current_edge.from, current_edge.to) + 1});

        int new_vertex = visited[current_edge.from] ? current_edge.to : current_edge.from;
        visited[new_vertex] = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && graph[new_vertex][i] != 0) {
                pq.push({new_vertex, i, graph[new_vertex][i]});
            }
        }
    }

    sort(mst.begin(), mst.end());

    for (auto edge: mst) {
        std::cout << edge.first << " " << edge.second << std::endl;
    }

    return 0;
} //Проходит только 13 тестов
