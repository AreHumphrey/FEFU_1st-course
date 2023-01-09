#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int ArrA[n][m];
    for(int i = 0; i < n; ++i){
        ArrA[i][0] = 1;
    }
    for(int i = 0; i < m; ++i){
        ArrA[0][i] = 1;
    }
    for(int i = 1; i < n; ++i)
        for(int j = 1; j < m; ++j)
            ArrA[i][j] = ArrA[i - 1][j] + ArrA[i][j - 1];
    for(int i = 0; i < n; ++i){
        cout <<  "  ";
        for(int j = 0; j < m; ++j){
            cout << ArrA[i][j] << "   ";
        }
        cout << endl;
    }
    return 0;
}