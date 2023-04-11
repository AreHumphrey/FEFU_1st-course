#include <fstream>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int countElem, ans = 0;
    input >> countElem;
    char permutations[100001];
    for (int i = 0; i < countElem; i++) {
        input >> permutations[i];
    }
    for (int i = 1; i < countElem; i++) {
        ans += (permutations[i] != permutations[i - 1]);
    }
    ans += (permutations[countElem - 1] == 'B');
    output << ans;
    return 0;
}

