#include <fstream>
#include <vector>
#include <string>

class Line {
public:
    int vowels;
    bool intonation;
};

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");

    bool mas[500] = {false};
    int masVowels[] = {'a', 'o', 'u', 'e', 'i', 'y', 'A', 'O', 'U', 'E', 'I', 'Y'};
    for (auto i: masVowels) {
        mas[i] = 1;
    }

    int countStr, countSongs;
    std::string a;
    std::vector<Line> arrStr, arrSongs;
    input >> countStr >> countSongs;
    getline(input, a);

    for (int i = 0; i < countStr; i++) {
        getline(input, a);
        int countVowels = 0;
        bool intonation = false;
        for (auto j: a) {
            if (mas[j]) {
                countVowels++;
            }
            if (j == '!') {
                intonation = true;
            }
        }
        arrStr.push_back({countVowels, intonation});
    }

    for (int i = 0; i < countSongs; i++) {
        getline(input, a);
        int count_vowels = 0;
        bool intonation = false;
        for (auto j: a) {
            if (mas[j]) {
                count_vowels++;
            }
            if (j == '!') {
                intonation = true;
            }
        }
        arrSongs.push_back({count_vowels, intonation});
    }

    std::vector<std::vector<int>> table(countSongs);
    for (int i = 0; i < countSongs; i++) {
        for (int j = 0; j < countStr; j++) {
            if (arrStr[j].vowels == arrSongs[i].vowels && arrStr[j].intonation == arrSongs[i].intonation) {
                table[i].push_back(arrStr[j].vowels);
            } else {
                table[i].push_back(0);
            }
            if (i > 0 && j > 0) {
                table[i][j] += table[i - 1][j - 1];
                int max = (table[i - 1][j] > table[i][j - 1]) ? table[i - 1][j] : table[i][j - 1];
                table[i][j] = (table[i][j] > max) ? table[i][j] : max;
            } else {
                if (i > 0) {
                    table[i][j] = (table[i][j] > table[i - 1][j]) ? table[i][j] : table[i - 1][j];
                }
                if (j > 0) {
                    table[i][j] = (table[i][j] > table[i][j - 1]) ? table[i][j] : table[i][j - 1];
                }
            }
        }
    }
    output << table[countSongs - 1][countStr - 1];
}
