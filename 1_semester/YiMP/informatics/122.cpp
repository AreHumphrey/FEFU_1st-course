#include <iostream>
using namespace std;
int main() {
    int n, m, rezultat;
    cin >> n >> m;
    rezultat = (1 << n) + (1 << m);
    cout << rezultat << endl;
}
