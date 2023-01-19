#include <iostream>
using namespace std;
int main()
{
    int f;
    cin >> f;
    int hour = (f / 3600) % 24;
    f = f % 3600;
    int minet = (f / 60);
    f = f % 60;
    int second = f;
    cout << hour << ":" << (minet / 10) << (minet % 10) << ':' << (second / 10) << (second % 10);
}