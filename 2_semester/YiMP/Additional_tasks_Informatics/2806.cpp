#include <iostream>

int main() {
    long long x1, x2, x3, y1, y2, y3;
    std::cin >> x1 >> y1 >> x2 >> y2>> x3 >> y3;
    if ((x2 - x1) * (x3 - x1) + (y2 - y1) * (y3 - y1) == 0) {
        std::cout << x1 + (x2 - x1) + (x3 - x1) << " " << y1 + (y2 - y1) + (y3 - y1);
    }
    if ((x1 - x2) * (x3 - x2) + (y1 - y2) * (y3 - y2) == 0) {
        std::cout << x2 + (x1 - x2) + (x3 - x2) << " " << y2 + (y1 - y2) + (y3 - y2);
    }
    if ((x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) == 0) {
        std::cout << x3 + (x1 - x3) + (x2 - x3) << " " << y3 + (y1 - y3) + (y2 - y3);
    }

}
