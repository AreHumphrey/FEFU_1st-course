#include <iostream>


int main() {
    int x1, x2, x3, y1, y2, y3, n;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> n;
    if (x1 == x2) {
        std::cout << x2 << " ";
    }
    else {
        std::cout << (x2 - x1) * n + x1 << " ";
    }
    if (y1 == y2) {
        std::cout << y2 << std::endl;
    }
    else {
        std::cout << (y2 - y1) * n + y1 << std::endl;
    }
    if (x1 == x3) {
        std::cout << x3 << " ";
    }
    else {
        std::cout << (x3 - x1) * n + x1 << " ";
    }
    if (y1 == y3) {
        std::cout << y3 << std::endl;
    }
    else {
        std::cout << (y3 - y1) * n + y1 << " ";
    }
}
