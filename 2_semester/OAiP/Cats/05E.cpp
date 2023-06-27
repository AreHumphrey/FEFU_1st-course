#include <iostream>
#include <algorithm>
#include <queue>



int compareDescending(int const &i, int const &j) {
    return i > j;
}

int pairCompDescending(std::pair<int, int> const &i, std::pair<int, int> const &j) {
    return i.first > j.first;
}

int main() {
    int n;

    std::cin >> n;

    int a[n], ans[n];
    std::pair<int, int> b[n];

    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++) {
        b[i].second = i;
        std::cin >> b[i].first;
    }

    std::sort(a, a + n, compareDescending);
    std::sort(b, b + n, pairCompDescending);

    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (a[i] <= b[i].first)
            ans[b[i].second] = a[i];
        else {
            flag = false;
            break;
        }
    }

    std::priority_queue<int> curr;
    if (flag) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            while (cur < n and b[cur].first >= a[i]) {
                curr.push(b[cur].second);
                cur++;
            }
            ans[curr.top()] = a[i];
            curr.pop();
        }
        for (int i = 0; i < n; i++)
            std::cout << ans[i] << ' ';
    } else
        std::cout << "-1";

    return 0;
}
