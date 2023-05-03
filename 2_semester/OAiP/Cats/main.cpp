#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
#include <math.h>

class Rectangle;

class Point {
public:
    Rectangle *rect;
    int x, y;
    double angle;
    char vertex;
};

class Rectangle {
public:
    int index;
    Point *a, *b, *c, *d;
    bool active;
    double distance;
};

double getAngle(int x, int y) {
    double angle = atan2(y, x);
    if (angle < 0) {
        angle += 2 * M_PI;
    }
    return angle;
}

double DistanceTo(const Rectangle &rect) {
    double x = (rect.a->x + rect.c->x) / 2.0;
    double y = (rect.a->y + rect.c->y) / 2.0;
    return hypot(x, y);
}

class DistanceComparison {
public:
    bool operator()(const Rectangle *const &r1, const Rectangle *const &r2) const {
        return r1->distance < r2->distance;
    }
};

Point *maxPoint(Rectangle rect) {
    if (rect.a->x >= 0 && rect.a->y <= 0 && rect.d->y >= 0) {
        return rect.d;
    }
    Point *MaxPoint = rect.d;
    Point *points[] = {rect.c, rect.b, rect.a};
    for (auto &point: points) {
        if (point->angle > MaxPoint->angle) {
            MaxPoint = point;
        }
    }
    return MaxPoint;
}

int main() {
    std::ifstream input("input.txt");
    std::fstream output("output.txt");
    int n;
    input >> n;
    std::vector<Rectangle> rectangles(n);
    std::vector<Point *> points;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        input >> a >> b >> c >> d;
        rectangles[i].index = i;
        rectangles[i].a = new Point{&rectangles[i], a, c, getAngle(a, c), 'a'};
        rectangles[i].b = new Point{&rectangles[i], b, c, getAngle(b, c), 'b'};
        rectangles[i].c = new Point{&rectangles[i], b, d, getAngle(b, d), 'c'};
        rectangles[i].d = new Point{&rectangles[i], a, d, getAngle(a, d), 'd'};
        for (auto &point: {rectangles[i].a, rectangles[i].b, rectangles[i].c, rectangles[i].d}) {
            points.emplace_back(point);
        }
        rectangles[i].distance = DistanceTo(rectangles[i]);
    }
    sort(points.begin(), points.end(), [](const Point *a, const Point *b) {
        if (a->angle == b->angle) {
            if (a->rect == b->rect) {
                return a->vertex < b->vertex;
            } else {
                return a->rect->distance < b->rect->distance;
            }

        }
        return a->angle < b->angle;
    });
    std::set<Rectangle *, DistanceComparison> tree;
    std::set<int> arrIndex;
    for (int i = 0; i < n; i++) {
        if (rectangles[i].a->x >= 0 and rectangles[i].a->y <= 0 and rectangles[i].d->y >= 0) {
            rectangles[i].active = true;
            tree.insert(&rectangles[i]);
        }
    }
    if (!tree.empty()) {
        arrIndex.insert((*tree.begin())->index);
    }
    Point *previousPoint = nullptr;
    for (auto p: points) {
        Rectangle *rect = p->rect;
        int previousIndex = (tree.empty() ? -1 : (*tree.begin())->index);
        if (not rect->active) {
            rect->active = true;
            tree.insert(rect);
        } else if (p == maxPoint(*rect)) {
            rect->active = false;
            tree.erase(rect);
            previousPoint = p;
        }
        if (not tree.empty() and (*tree.begin())->index != previousIndex) {
            if (!previousPoint) {
                arrIndex.insert((*tree.begin())->index);
            } else if (maxPoint(*(*tree.begin()))->angle != previousPoint->angle) {
                arrIndex.insert((*tree.begin())->index);
            }
        }
    }
    for (auto index: arrIndex) {
        output << index << std::endl;
    }
    return 0;
}
