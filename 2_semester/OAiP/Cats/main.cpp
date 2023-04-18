#include <fstream>
#include <vector>
#include <algorithm>

struct run {
    int team, problem, time, attempt[20];
};

struct result {
    int team, problem, time, condition;
};

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int c, n;
    input >> c >> n;
    std::vector<run> teams(c);
    std::vector<result> inf;
    std::vector<std::vector <bool>> tasks(c, std::vector<bool>(20, {false}));

    for (int i = 0; i < n; i++) {
        int team, problem, time, attempt;
        input >> team >> problem >> time >> attempt;
        inf.push_back({team, problem, time, attempt});
    }

    for (int i = 0; i < c; i++) {
        teams[i].team = i + 1;
    }

    std::sort(inf.begin(), inf.end(), [](result l, result r) {
        return l.time < r.time;
    });

    for (auto r: inf) {
        if (r.condition && !tasks[r.team - 1][r.problem - 1]) {
            teams[r.team - 1].problem++;
            teams[r.team - 1].time += 1200 * teams[r.team - 1].attempt[r.problem - 1] + r.time;
            tasks[r.team - 1][r.problem - 1] = true;
        } else if (!tasks[r.team - 1][r.problem - 1]) {
            teams[r.team - 1].attempt[r.problem - 1]++;
        }
    }

    std::sort(teams.begin(), teams.end(), [](run &l, run &r) {
        if (l.problem > r.problem) {
            return true;
        } else {
            if (l.problem == r.problem && l.time < r.time) {
                return true;
            }
            if (l.problem == r.problem && l.time == r.time) {
                return l.team < r.team;
            }
        }
        return false;
    });
    for (auto a: teams) {
        output << a.team << " ";
    }
    return 0;
}
