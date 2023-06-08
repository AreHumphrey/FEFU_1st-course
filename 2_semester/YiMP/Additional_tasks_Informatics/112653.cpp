#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<int> students(n);
    for (int i = 0; i < n; i++) {
        cin >> students[i];
    }

    int min_distance = INT_MAX;
    int best_school = -1;

    for (int i = 0; i < n; i++) {
        int distance = 0;
        for (int j = 0; j < n; j++) {
            if (students[j] > 0) {
                if (graph[i][j] == 0) {
                    // Если между деревнями нет дороги,
                    // стоимость доставки каждого ученика - 10000
                    distance += students[j] * 10000;
                } else {
                    distance += students[j] * graph[i][j];
                }
            }
        }
        if (distance < min_distance) {
            min_distance = distance;
            best_school = i + 1;
        }
    }

    cout << best_school << " " << min_distance << endl;

    return 0;
}
