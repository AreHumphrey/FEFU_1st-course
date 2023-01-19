#include <iostream>
using namespace std;
int main()
{
    int A, n;
    cin >> A >> n;
    A = A & ~(~0 << n);
    cout << A << endl;
}
