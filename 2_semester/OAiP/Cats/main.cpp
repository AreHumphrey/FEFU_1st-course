#include <fstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <list>

const int BASE = 120;
const int MOD = 4 * 1000;

class HashTable {
private:
    std::list<std::pair<std::string, int>> table[::MOD];

public:
    void add(std::string, int);

    int get(std::string);
};


unsigned long long hashing(std::string key) {
    unsigned long long result = 0;

    for (char c: key)
        result = (result * ::BASE + (c - 'a' + 1)) % ::MOD;

    return result;
}


void HashTable::add(std::string key, int value) {
    unsigned long long hashIdx = hashing(key);
    auto &cell = table[hashIdx];
    auto bit = std::begin(cell);
    bool keys = false;

    while (bit != std::end(cell)) {
        if (bit->first == key) {
            keys = true;
            bit->second = value;

            break;
        }
        bit++;
    }

    if (!keys) {
        cell.emplace_back(key, value);
    }
}


int HashTable::get(std::string key) {
    unsigned long long hashIdx = hashing(key);
    auto &cell = table[hashIdx];
    auto bIt = std::begin(cell);

    while (bIt != std::end(cell)) {
        if (bIt->first == key)
            return bIt->second;

        bIt++;
    }

    return 0;
}


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int n, m, k;
    HashTable hashTable;
    std::string keyP1, keyP2;
    std::vector<std::string> allKeys;

    input >> n;

    int answers[n][n];

    memset(answers, 0, sizeof(answers));

    for (int i = 0; i < n; ++i) {
        input >> keyP1;
        allKeys.push_back(keyP1);
    }

    std::sort(allKeys.begin(), allKeys.end());

    for (int i = 0; i < n; i++) hashTable.add(allKeys[i], i);

    input >> m;

    for (int i = 0; i < m; i++) {
        input >> keyP1 >> keyP2;

        answers[hashTable.get(keyP1)][hashTable.get(keyP2)] = 1;
        answers[hashTable.get(keyP2)][hashTable.get(keyP1)] = 2;
    }

    input >> k;

    for (int i = 0; i < k; i++) {
        input >> keyP1 >> keyP2;

        output << answers[hashTable.get(keyP1)][hashTable.get(keyP2)] << " ";
    }

    return 0;
}
