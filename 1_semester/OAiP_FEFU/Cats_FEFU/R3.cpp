#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
struct IndexObgect {
    string Number;
    int StraightLinesInNumbers;
    int SlopingLinesInNumbers;
};
bool FindString(string &StringFirst, string &StringSecond) {
    if (StringFirst.size() < StringSecond.size())
        return true;
    else if (StringSecond.size() < StringFirst.size())
        return false;

    for (int i = 0; i < StringFirst.size(); i++) {
        if (int(StringFirst[i]) < int(StringSecond[i]))
            return true;
        else if (int(StringFirst[i]) > int(StringSecond[i]))
            return false;
    }

    return false;
}

int main() {
    fstream InFail("input.txt");
    ofstream OutFail("output.txt");
    int StraightLines, SlopingLines;
    InFail >> StraightLines >> SlopingLines;
    auto **Otvet = new string *[StraightLines + 1];
    for (int i = 0; i <= StraightLines; i++) {
        Otvet[i] = new string[SlopingLines + 1];
        fill(&Otvet[i][0], &Otvet[i][SlopingLines + 1], "-1");
    }
    IndexObgect LinsSlant[8] = {
            {"0", 6, 0},
            {"1", 2, 1},
            {"2", 3, 1},
            {"3", 2, 2},
            {"4", 4, 0},
            {"5", 5, 0},
            {"6", 4, 1},
            {"8", 7, 0},
    };
    for (auto &Digit: LinsSlant) {
        if (Digit.Number == "0")
            continue;
        if (Digit.StraightLinesInNumbers <= StraightLines && Digit.SlopingLinesInNumbers <= SlopingLines)
            Otvet[Digit.StraightLinesInNumbers][Digit.SlopingLinesInNumbers] = Digit.Number;
    }
    for (int i = 0; i <= StraightLines; i++) {
        for (int j = 0; j <= SlopingLines; j++) {
            string NewValue = Otvet[i][j];
            for (auto &Digit: LinsSlant) {
                int prev_y = i - Digit.StraightLinesInNumbers, prev_x = j - Digit.SlopingLinesInNumbers;
                if (prev_y >= 0 && prev_x >= 0) {
                    auto PrevNum = Otvet[prev_y][prev_x];
                    auto this_num = PrevNum + Digit.Number;
                    if (PrevNum != "-1" && (NewValue == "-1" or FindString(this_num, NewValue)))
                        NewValue = this_num;
                }
            }
            Otvet[i][j] = NewValue;
        }
    }
    if (Otvet[StraightLines][SlopingLines] == "-1")
        OutFail << "Wrong";
    else
        OutFail << Otvet[StraightLines][SlopingLines];

}
