#include <bits/stdc++.h>

int main() {
    std::ifstream input("input.txt");
    unsigned long long n;
    int k;
    input >> n >> k;
    if (k < 3) {
        std::cout << n;
    } else {
        int maxDegree = (int) trunc(log2(n) / log2(k));
        auto counter = (unsigned long long) (2 * pow(2, maxDegree - 1));
        if (n == 1) {
            counter = 1;
        }
        std::string s;
        while (n > 0) {
            int buff = n % k <= 9 ? n % k : 9;
            s = std::to_string(buff) + s;
            n /= k;
        }

        bool flag = true;
        int startIndex = -1;
        for (int i = 0; i < s.length() and flag; i++) {
            if (s[i] > '1') {
                if (i == 0) {
                    startIndex = 1;
                }
                std::string sub(s.length() - i, '1');
                s.replace(i, s.length() - i, sub);
                flag = false;
            }
            if (s[i] > '0' and startIndex == -1 and i != 0)
                startIndex = i;
        }

        if (startIndex == -1) {
            std::cout << counter;
        } else {
            char sub[s.length() - startIndex];
            std::strcpy(sub, &s[startIndex]);
            unsigned long long i = std::bitset<std::numeric_limits<unsigned long long>::digits>(sub).to_ullong();

            counter += i;
            std::cout << counter;
        }
    }

    return 0;
}
