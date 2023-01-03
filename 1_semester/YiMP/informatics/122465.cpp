#include <iostream>

using namespace std;

int n, i, k, a[251], b, m;

int main()
{
    cin >> n;
    cin >> k;
    i = -1;

    while (k != 0)
    {
        i++;
        a[i] = k % 10;
        k = k / 10;
    }

    m = i;
    b = a[m];
    m--;

    if (b < n)
    {
        b = b * 10 + a[m];
        m--;
    }

    k = b % n;

    while (m >= 0)
    {
        k = k * 10 + a[m];
        m--;
        k = k % n;
    }

    cout << k;
}