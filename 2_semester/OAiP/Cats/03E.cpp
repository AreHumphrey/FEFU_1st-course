#include <fstream>
#include <string>
#include <map>
#include <vector>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    int L, M;
    input >> L >> M;
    std::string s;
    input >> s;

    std::map<std::string, int> freq;
    std::vector<int> freqCount(M + 1);
    int max_freq = 0;

    for (int i = 0; i <= M - L; ++i) {
        std::string sub = s.substr(i, L);
        freq[sub]++;
        if (freqCount[freq[sub] - 1] > 0)
            freqCount[freq[sub] - 1]--;
        freqCount[freq[sub]]++;
        max_freq = std::max(max_freq, freq[sub]);
    }
    output << max_freq << " ";

    for (int i = 1; i <= s.size() - M; ++i) {
        std::string old_sub = s.substr(i - 1, L);
        freqCount[freq[old_sub]]--;
        freq[old_sub]--;
        if (freqCount[max_freq] == 0)
            max_freq--;
        freqCount[freq[old_sub]]++;

        std::string new_sub = s.substr(i + M - L, L);
        freq[new_sub]++;
        if (freqCount[freq[new_sub] - 1] > 0)
            freqCount[freq[new_sub] - 1]--;
        freqCount[freq[new_sub]]++;
        max_freq = std::max(max_freq, freq[new_sub]);

        output << max_freq << " ";
    }

    return 0;
}
