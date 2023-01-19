#include <iostream>
using namespace std;
int main()
{
    int a, b, l, N;
    cin >> a;
    cin >> b;
    cin >> l;
    cin >> N;
    int shnur = 2 * l + N * a + a * (N - 1) + 2 * b * (N - 1);
    cout << shnur << endl;
}
