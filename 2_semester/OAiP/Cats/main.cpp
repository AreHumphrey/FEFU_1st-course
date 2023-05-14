#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
class Button {
public:
    int x;
    int y;
};

class Position {
public:
    int leftPos;
    int rightPos;
    int count = 0;
    double sum = 0;
    int index;
};

double distance(Button l, Button r) {
    return sqrt(pow(l.x - r.x, 2) + pow(l.y - r.y, 2));
}

int main() {
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    output << std::setprecision(16);
    Button buttons[10] = {4, 2, 1, 1, 1, 2, 1, 3, 2, 1, 2, 2, 2, 3, 3, 1, 3, 2, 3, 3};
    int count, a, left, right;
    double d;
    input >> count;
    std::vector <Position> positions;
    std::vector <Position> newPositions;
    positions.push_back({ 4, 6, 0, 0 });
    Position table[10][10];
    for (int i = 1; i <= count; i++) {
        input >> a;
        for (int j = 0; j < size(positions); j++) {
            left = positions[j].leftPos;
            right = positions[j].rightPos;
            d = distance(buttons[right], buttons[a]);
            if (buttons[a].y >= buttons[left].y && a != left) {
                if (table[left][a].count == i) {
                    if (table[left][a].sum > positions[j].sum + d) {
                        table[left][a].sum = positions[j].sum + d;
                        newPositions[table[left][a].index].sum = positions[j].sum + d;
                    }
                }
                else {
                    table[left][a].count = i;
                    table[left][a].sum = positions[j].sum + d;
                    newPositions.push_back({left, a, i, positions[j].sum + d});
                    table[left][a].index = size(newPositions) - 1;
                }
            }
            d = distance(buttons[left], buttons[a]);
            if (buttons[a].y <= buttons[right].y && a != right) {
                if (table[a][right].count == i) {
                    if (table[a][right].sum > positions[j].sum + d) {
                        table[a][right].sum = positions[j].sum + d;
                        newPositions[table[a][right].index].sum = positions[j].sum + d;
                    }
                }
                else {
                    table[a][right].count = i;
                    table[a][right].sum = positions[j].sum + d;
                    newPositions.push_back({a, right, i, positions[j].sum + d });
                    table[a][right].index = size(newPositions) - 1;
                }
            }
        }
        positions.clear();
        positions = newPositions;
        newPositions.clear();
    }
    double min = pow(10, 9);
    for (int i = 0; i < size(positions); i++) {
        min = (min < positions[i].sum) ? min : positions[i].sum;
    }
    output << min << std::endl;
    return 0;
}
