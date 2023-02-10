#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    int n;
    InPut >> n;
    int Map[n][n];
    int MaxDiff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            InPut >> Map[i][j];
            if (i > 0) {
                MaxDiff = max(MaxDiff, abs(Map[i][j] - Map[i - 1][j]));
            }
            if (j > 0) {
                MaxDiff = max(MaxDiff, abs(Map[i][j] - Map[i][j - 1]));
            }
        }
    }
    OutPut << MaxDiff << endl;
    OutPut.close();
    InPut.close();
}
