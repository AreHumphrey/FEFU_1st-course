#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <tuple>
#include <set>

int w[9][9];
int way[9];
int bestWay[9];
int n, k, best;
bool vizit[9];

void findCycles(int start, int cur, int remains) {
    if (remains == 1) {
        if (w[cur][start] != 0) {
            way[k] = start;
            int prev = start, len = 0;
            for (int i = 1; i <= k; i++) {
                len += w[prev][way[i]];
                prev = way[i];
            }
            if (len < best) {
                best = len;
                for (int i = 0; i <= k; i++) {
                    bestWay[i] = way[i];
                }
            }
        }
        return;
    }

    vizit[cur] = true;

    for (int i = start + 1; i <= n; i++) {
        if (!vizit[i] && w[cur][i] != 0) {
            way[k - remains + 1] = i;
            findCycles(start, i, remains - 1);
        }
    }
    vizit[cur] = false;
}

int main() {
    std::cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cin >> w[i][j];
        }
    }

    std::cin >> k;
    best = INT32_MAX;

    for (int i = 1; i <= n; i++) {
        way[0] = i;
        findCycles(i, i, k);
    }

    if (best == INT32_MAX) {
        std::cout << 0 << '\n';
    } else {
        std::cout << best << '\n';

        for (int i = 0; i <= k; i++) {
            std::cout << bestWay[i] << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}
