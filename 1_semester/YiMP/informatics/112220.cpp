#include <iostream>
using namespace std;
int main()
{
    int a, b, nod = 0, i = 0;
    cin >> a >> b;
    if (a < b) {
        for (i;;) {
            i++;
            nod = a;
            a = b % a;
            if (a == 0) {
                cout << nod << "\n" << i << endl;
                break;

            }
            b = nod;
        }
    }
    if (a > b) {
        for (i;;) {
            i++;
            nod = b;
            b = a % b;
            if (b == 0) {
                cout << nod << "\n" << i << endl;
                break;
            }
            a = nod;
        }
    }
}
