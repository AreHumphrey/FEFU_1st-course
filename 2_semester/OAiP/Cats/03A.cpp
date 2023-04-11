#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

typedef set<long long> Numbers;

int main() {
    Numbers setn;
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    long long num;
    for (; InPut >> num;) {
        if (num > 0) setn.insert(num);
        if (num < 0) setn.erase(-num);
        if (num == 0) {
            set<long long>::iterator it;
            for (it = setn.begin(); it != setn.end(); it++) {
                OutPut << *it << " ";
            }
            break;

        }
    }
    return 0;

}
