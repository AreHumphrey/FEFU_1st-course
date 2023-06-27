#include <vector>
#include <cstdio>
#include <string>


class HashTable {
private:
    std::vector<std::pair<std::string , int>> table;
public:
    int amountObj = 0;
    void add(std::string, int);
    int get(int);
    std::string getObj(int);
};


void HashTable::add(std::string key, int value) {
    auto beg = table.begin();
    bool keyExst = false;

    while (beg != table.end()) {
        if (beg->first == key) {
            keyExst = true;
            beg->second += value;
            break;
        }
        beg++;
    }

    if (!keyExst) {
        table.emplace_back(key, value);
        amountObj++;
    }
}


int HashTable::get(int key) {
    return table[key].second;
}


std::string HashTable::getObj(int key) {
    return table[key].first;
}


int main() {
    FILE *in, *out;
    FILE *input = fopen("schools.in", "r");
    FILE *output = fopen("schools.out", "w");
    HashTable schoolList;
    int count, schoolAmount = 0;

    fscanf(input, "%d", &count);

    for (int i = 0; i <= count; i++) {
        char schoolName[101];
        fscanf(input, "%*[^0123456789]%100[0123456789]", schoolName);

        schoolList.add(schoolName, 1);
    }

    for (int i = 0 ; i < schoolList.amountObj; i++) {
        if (schoolList.get(i) <= 5)schoolAmount++;
    }

    fprintf(output, "%d\n", schoolAmount);

    for (int i = 0 ; i < schoolList.amountObj; i++) {
        if (schoolList.get(i) <= 5)
            fprintf(output, "%s\n", schoolList.getObj(i).c_str());
    }
    
}
