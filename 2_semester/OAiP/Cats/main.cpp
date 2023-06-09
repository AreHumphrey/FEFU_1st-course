#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n, C, P, T;
    input >> n >> C >> P >> T;
    vector<int> a(n);
    vector<int> b(n);
    b.assign(n, 0);
    for (int i = 0; i < n; ++i) {
        input >> a[i];

    }
    int l = 0, r = 0, mid = 0, k;
    while (l < r) {
        mid = (l + r + 1) / 2;
        int cM = mid;
        for (int i = 0; i < n; i++) {
            b[i] = min(a[i], cM);
            cM -= b[i];
        }
        int pos = n - 1;
        int sumT = 0;
        while (true) {
            while (pos >= 0 && !b[pos]) {
                pos--;
            }
            if (pos < 0) break;
            k = (b[pos] + C - 1) / C;
            sumT += 2 * k * (pos + 1);
            int const_kc = k * C;
            while (pos >= 0 && const_kc != 0) {
                if (!b[pos]) pos--;
                int minf = min(b[pos], const_kc);
                b[pos] -= minf;
                const_kc -= minf;
            }
        }
        if (sumT <= T / P) {
            l = mid;
        } else {
            r = mid - 1;
        }

    }
}
