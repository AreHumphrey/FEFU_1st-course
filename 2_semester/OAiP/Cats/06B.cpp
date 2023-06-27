#include <fstream>
#include <vector>

class Timer {
public:
    int up = 0;
    int down = 0;
};

class Table {
public:
    bool ex = false;
    int time;
    int timer;
    Table *id;
};

class Result {
public:
    int time;
    int timer;
};

Table arrTable[500][100][100];

Table *getOptimalState(Timer a, Timer b, int t, int T, Table *id) {
    if (a.up > 0 && b.up > 0) {
        int min = (a.up < b.up) ? a.up : b.up;
        a.up -= min;
        b.up -= min;
        a.down += min;
        b.down += min;
        t -= min;
    } else {
        if (a.up > 0) {
            a.down += a.up;
            t -= a.up;
            a.up = 0;
        }
        if (b.up > 0) {
            b.down += b.up;
            t -= b.up;
            b.up = 0;
        }
    }
    if (t > 0) {
        if (!arrTable[T - t][a.up][b.up].ex) {
            arrTable[T - t][a.up][b.up].id = id;
            id = &arrTable[T - t][a.up][b.up];

            arrTable[T - t][a.up][b.up].ex = true;
            arrTable[T - t][a.up][b.up].time = T - t;
            Table *m;

            arrTable[T - t][a.up][b.up].timer = 1;
            std::swap(a.up, a.down);
            m = getOptimalState(a, b, t, T, id);
            if (m) {
                return m;
            }
            std::swap(a.up, a.down);

            arrTable[T - t][a.up][b.up].timer = 2;
            std::swap(b.up, b.down);
            m = getOptimalState(a, b, t, T, id);
            if (m) {
                return m;
            }
            std::swap(b.up, b.down);

            arrTable[T - t][a.up][b.up].timer = 3;
            std::swap(a.up, a.down);
            std::swap(b.up, b.down);
            m = getOptimalState(a, b, t, T, id);
            if (m) {
                return m;
            }
        }
    }
    if (!t && !a.up && !b.up) {
        return id;
    } else {
        while (id) {
            id->ex = 0;
            id = id->id;
        }
        return nullptr;
    }
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n, t, a, b;
    input >> n;
    Table *currentState = NULL;
    std::vector<Result> solutions;
    for (int i = 0; i < n; i++) {
        input >> t >> a >> b;
        Timer A = {0, a}, B = {0, b};
        currentState = getOptimalState(A, B, t, t, nullptr);
        while (currentState) {
            solutions.push_back({currentState->time, currentState->timer});
            currentState->ex = false;
            currentState = currentState->id;
        }
        output << size(solutions) << std::endl;
        for (int j = size(solutions); j > 0; j--) {
            output << solutions[j - 1].time << " " << solutions[j - 1].timer << std::endl;
        }
        solutions.clear();
    }
}
