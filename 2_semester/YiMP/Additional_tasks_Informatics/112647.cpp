#include <iostream>
#include <string>


void calc(int** mp, std::string* v, int n, int& r1, int& r2) {
    r1 = 0;
    r2 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (mp[i][j] != 0) {
                if (v[i] == v[j]) {
                    r1++;
                }
                else {
                    r2++;
                }
            }
        }
    }
}

int main()
{
    int** mp;
    std::string* v;

    int r1 = 0;
    int r2 = 0;

    int n;

    std::cin >> n;

    v = new std::string[n];
    mp = new int* [n];

    for (int i = 0; i < n; i++) {
        mp[i] = new int[n];

        for (int j = 0; j < n; j++) {
            std::cin >> mp[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    calc(mp, v, n, r1, r2);

    std::cout << r1 << ' ' << r2;
}
