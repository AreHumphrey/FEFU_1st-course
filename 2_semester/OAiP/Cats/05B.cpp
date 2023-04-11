#include <fstream>
#include <set>

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int cntPupils, sipsWater;

    input >> cntPupils >> sipsWater;

    long long sum = 0;
    std::multiset<int> thirst;

    for (int i = 0; i < cntPupils; i++) {
        int thirstSips;
        input >> thirstSips;
        sum += thirstSips;
        thirst.insert(thirstSips);
    }
    for (int i = 0; i < sipsWater && sum > 0; i++) {
        auto max = thirst.rbegin();
        auto result = *max / 10;
        sum -= *max - result;
        thirst.erase(thirst.find(*max));
        thirst.insert(result);
    }
    output << sum;

}
