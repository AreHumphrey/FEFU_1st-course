#include <fstream>
#include <algorithm>

int main() {

    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    long long n, c, p, t, sumPassengers = 0;

    input >> n >> c >> p >> t;
    long long passengers[n], remPassengers[n];
    long long l = 0, r, mid, k, constCapacity;

    for (long long i = 0; i < n; i++) {
        remPassengers[i] = 0;
        input >> passengers[i];
        sumPassengers += passengers[i];

    }
    r = sumPassengers;
    while (l < r) {
        mid = (l + r + 1) / 2;
        long long permLift = mid;

        for (long long i = 0; i < n; i++) {
            remPassengers[i] = std::min(passengers[i], permLift);
            permLift -= remPassengers[i];
        }

        long long pos = n - 1, sumT = 0;

        while (true) {
            while (pos >= 0 && !remPassengers[pos]) {
                pos--;
            }
            if (pos < 0) {
                break;
            }
            k = (remPassengers[pos] + c - 1) / c;
            sumT += 2 * k * (pos + 1);
            constCapacity = k * c;

            while (pos >= 0 && constCapacity != 0) {
                if (!remPassengers[pos]) {
                    pos--;
                }
                long long availableCapacity = std::min(remPassengers[pos], constCapacity);
                remPassengers[pos] -= availableCapacity;
                constCapacity -= availableCapacity;
            }
        }
        if (sumT <= t / p) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    output << l;
    return 0;
}
