#include <iostream>
using namespace std;
int main()
{
    int A, i;
    cin >> A >> i;
    A ^= 1 << i;
    cout << A << endl;
}