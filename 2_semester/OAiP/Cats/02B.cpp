#include <fstream>
#include <vector>
#include <queue>
#include <functional>
#include <cassert>

// Необходимо зафиксировать верхнюю границу области пересечения, и найти оптимальную правую границу области пересечения:
// Для этого нужно отфильтровать фигуры + выкинуть фигуры у которых верхняя граница меньшее
//  Оставшиеся фигуры отсортировать по правой границе по возрастанию. Берем  k прямоугольников с самыми большими границами
// Самая маленькая - оптимальная
// N^2 * log(N)
struct Rect {
    int x, y;
};

int main() {
    std::ifstream input("power.in");
    std::ofstream output("power.out");
    int n, k;
    input >> n >> k;
    std::vector<Rect> rects(n);
    for (int i = 0; i < n; ++i) {
        input >> rects[i].x >> rects[i].y;
    }
    std::sort(rects.begin(), rects.end(), [](const Rect &left, const Rect &right) {
        return left.y > right.y;

    });
    std::priority_queue<int, std::vector<int>, std::greater<>> xs;
    long long maxSquare = 0;
    for (const Rect &r: rects) {
        xs.push(r.x);
        if (xs.size() > k) {
            xs.pop();
        }
        assert(xs.size() <= k);
        if (xs.size() == k) {
            maxSquare = std::max(maxSquare, 1LL * r.y * xs.top());
        }
    }
    output << maxSquare;

}
