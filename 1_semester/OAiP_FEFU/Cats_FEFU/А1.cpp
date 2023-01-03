
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int a, b;
    ifstream file1("input.txt");
    ofstream file2("output.txt");
    file1 >> a;
    file1 >> b;

    for (int i = 2; i < min(a, b); i++) {
        while (a % i == 0 && b % i == 0) {
            a /= i;
            b /= i;
        }
    }
    int steps2 = 0, steps5 = 0;
    while (b % 2 == 0 || b % 5 == 0) {
        if (b % 2 == 0) {
            steps2++;
            b /= 2;
        }if (b % 5 == 0) {
            steps5++;
            b /= 5;

        }
    }


    file2 << b << ' ' << max(steps2, steps5);
    file2.close();
    return 0;
}
