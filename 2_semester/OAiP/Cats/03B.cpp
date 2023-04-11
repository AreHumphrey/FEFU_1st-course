#include <fstream>
#include <vector>

using namespace std;
const int Prime = 31;
const int MOD = 1e9 + 7;
vector<long long> Deg = {1};
vector<long long> Hashes = {0};

long long Hash(int Left, int Lenght);

int main() {
    fstream InPut("input.txt");
    ofstream OutPut("output.txt");
    string Word;
    int CountOper, a, b, c, d;
    InPut >> Word;
    InPut >> CountOper;
    for (char i: Word) {
        int x = (int) (i - 'a' + 1);
        Hashes.push_back((Hashes.back() * Prime + x) % MOD);
        Deg.push_back((Deg.back() * Prime) % MOD);
    }
    for (int i = 0; i < CountOper; i++) {
        InPut >> a >> b >> c >> d;
        if (!((Hash(a - 1, b - a + 1) - Hash(c - 1, d - c + 1)) % MOD))
            OutPut << "Yes\n";
        else
            OutPut << "No\n";
    }


}

long long Hash(int Left, int Lenght) {
    return Hashes[Left + Lenght] - Hashes[Left] * Deg[Lenght];
}
