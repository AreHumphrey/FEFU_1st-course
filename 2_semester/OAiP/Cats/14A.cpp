#include <fstream>
#include <string>

int main() {
    std::string s1, s2;
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    getline(input, s1);
    getline(input, s2);
    size_t n = s1.length();
    size_t m = s2.length();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && s1[i + j] == s2[j]) {
            j++;
        }
        if (j == m) {
            output << i + 1 << std::endl;
            return 0;
        }
    }
    output << -1 << std::endl;
    return 0;
}
