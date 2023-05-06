#include <iostream>

int main() {
    int n;
    std::cin >> n;
    int a[2 * n], b[2 * n], l = 0, r = 0, i, d;
    for (i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
        a[n + i] = a[i];
        b[n + i] = b[i];
    }
    for (i = 0; i < n; i++) {
        for (int o = i + 2; o < i + 2 + n - 2; o++) {
            d = (a[i + 1] - a[i]) * (b[o] - b[i]) - (b[i + 1] - b[i]) * (a[o] - a[i]);
            if (d < 0 || l == 0) {
                r++;
            }
            if (d > 0 || r == 0) {
                l++;
            }
            if (r > 0 && l > 0) {
                break;
            }
        }
    }
    if (l > 0 && r == 0 || l == 0 && r > 0) {
        std::cout << "YES";
    }
    else {
        std::cout << "NO";
    }
    return 0;
}
