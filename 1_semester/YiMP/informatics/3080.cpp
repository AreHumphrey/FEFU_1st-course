#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int prev, cur, next;
    int dist = 0;
    int cur_dist = 0;
    int min_dist = 0;
    if (cin >> prev && prev != 0) {
        if (cin >> cur && cur != 0) {
            if (cin >> next) {
                int pos = 2;
                while (next != 0) {
                    if (prev < cur && cur > next) {
                        if (dist != 0) {
                            cur_dist = pos - dist;
                            if (min_dist == 0) {
                                min_dist = cur_dist;
                            }
                            else {
                                min_dist = min(cur_dist, min_dist);
                            }
                        }

                        dist = pos;
                    }
                    ++pos;
                    prev = cur;
                    cur = next;
                    cin >> next;
                }
            }
        }
    }

    cout << min_dist;
}