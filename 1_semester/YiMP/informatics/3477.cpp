#include <iostream>
using namespace std;
int main() {
    int h, a, b;
    cin >> h >> a >> b;
    cout << (h - b - 1) / (a - b) + 1;
}