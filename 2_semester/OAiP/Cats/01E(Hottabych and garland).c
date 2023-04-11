#include <vector>
#include <fstream>
using namespace std;
int main() {
    ifstream InPut("input.txt");
    ofstream OutPut("output.txt");
    vector<pair<string,vector<int>>> ColorsOfLamp;
    int CountLamp;
    bool Flag;
    InPut >> CountLamp;
    for ( auto i = 0; i < CountLamp;++i){
        string Str;
        InPut >> Str;
        Flag = false;
        for (auto & j : ColorsOfLamp) {
            if (j.first == Str) {
                j.second.push_back(i);
                Flag = true;
                break;
            }
        }//int j = 0; j < ColorsOfLamp.size(); j++
        if (!Flag) {
            ColorsOfLamp.emplace_back(Str, vector<int>());
            ColorsOfLamp.back().second.push_back(i);
        }
    }
    int Requests, min;
    bool Flag1, Flag2;
    InPut >> Requests;
    for (int z = 0; z < Requests; z++) {
        string ColorOfBegin, ColorOfEnd;
        InPut >> ColorOfBegin >> ColorOfEnd;
        min = INT_MAX;
        Flag1 = Flag2 = false;
        vector<int> ArrColorBeginSegment, ColorOfTheEndSegment;
        for (auto &j: ColorsOfLamp) {
            if (j.first == ColorOfBegin) {
                Flag1 = true;
                ArrColorBeginSegment = j.second;
            }
            if (j.first == ColorOfEnd) {
                Flag2 = true;
                ColorOfTheEndSegment = j.second;
            }
        }
        if (!Flag1 || !Flag2) {
            OutPut << -1 << '\n';
            continue;
        }
        if (ColorOfBegin == ColorOfEnd) {
            if (ArrColorBeginSegment.size() == 1) {
                OutPut << -2 << '\n';
                continue;
            }
            int Minimum = ArrColorBeginSegment[1] - ArrColorBeginSegment[0];
            for (int i = 1; i < ArrColorBeginSegment.size() - 1; i++) {
                if (ArrColorBeginSegment[i + 1] - ArrColorBeginSegment[i] < Minimum) {
                    Minimum = ArrColorBeginSegment[i + 1] - ArrColorBeginSegment[i];
                    if (Minimum == 1) {
                        break;
                    }
                }
            }
            OutPut << Minimum - 1 << '\n';
            continue;
        }
        int i = 0;
        int j = 0;
        min = abs(ArrColorBeginSegment[0] - ColorOfTheEndSegment[0]);
        for (;;) {
            if (ArrColorBeginSegment[i] > ColorOfTheEndSegment[j]) {
                j++;
            } else {
                i++;
            }
            if ((i >= ArrColorBeginSegment.size()) || (j >= ColorOfTheEndSegment.size())) {
                break;
            }
            if (min > abs(ArrColorBeginSegment[i] - ColorOfTheEndSegment[j])) {
                min = abs(ArrColorBeginSegment[i] - ColorOfTheEndSegment[j]);
            }
        }
        OutPut << min - 1 << '\n';
    }
    return 0;
}
