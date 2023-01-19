#include <iostream>
using namespace std;
int main() {
    int v, t;
    cin >> v >> t;
    int put;
    if (v > 0)
    {
        put = (v * t) % 109;
        cout << put << endl;
    }
    if (v < 0) {
        put = (109 + ((v * t) % 109)) % 109;;
        cout << put << endl;
    }
}