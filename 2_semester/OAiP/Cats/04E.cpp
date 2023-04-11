#include <fstream>
#include <algorithm>
#include <vector>


int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    std::vector<std::vector<double>> times(4, std::vector<double>(4));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            input >> times[i][j];
        }
    }
    std::vector<int> indexes = {0, 1, 2, 3};
    double minTime = 1e9;
    std::vector<int> result(4);
    do {
        double currentTime = times[0][indexes[0]] + times[1][indexes[1]] + times[2][indexes[2]] + times[3][indexes[3]];
        if (currentTime < minTime) {
            minTime = currentTime;
            result = indexes;
        }
    } while (next_permutation(indexes.begin(), indexes.end()));
    for (int x: result) {
        output << x + 1 << ' ';
    }
    output << std::endl;
    return 0;
}
