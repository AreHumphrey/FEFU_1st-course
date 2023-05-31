#include <iostream>

int main() {

    int n, ans = 0;
    std::cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++){
        for (int o = 0; o < n; o++){
            std::cin >> a[i][o];
        }
    }

    int w;
    for (int i = 0; i < n; i++){
        w = 0;
        for (int o = 0; o < n; o++){
            if (a[i][o] != 0 || a[o][i] != 0) {
                w++;
            }
        }
        if (w == 0) {
            ans++;
            std::cout << i+1 << " ";
        }
    }

    if (ans == 0) {
        std::cout << 0;
    }
}
