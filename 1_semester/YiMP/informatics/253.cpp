#include <iostream>
using namespace std;
int main() {
    int year;
    cin >> year;
    if (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0))
    {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}
