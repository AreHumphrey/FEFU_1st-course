#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;

class Deque {
private:
    int head, tail;
    int arr[MAX_SIZE];
public:
    Deque() : head(0), tail(0) {}
    void push_front(int x) {
        if (head == (tail + 1) % MAX_SIZE) {
            cout << "error\n";
        } else {
            head = (head - 1 + MAX_SIZE) % MAX_SIZE;
            arr[head] = x;
            cout << "ok\n";
        }
    }
    void push_back(int x) {
        if (head == (tail + 1) % MAX_SIZE) {
            cout << "error\n";
        } else {
            arr[tail] = x;
            tail = (tail + 1) % MAX_SIZE;
            cout << "ok\n";
        }
    }
    void pop_front() {
        if (head == tail) {
            cout << "error\n";
        } else {
            cout << arr[head] << "\n";
            head = (head + 1) % MAX_SIZE;
        }
    }
    void pop_back() {
        if (head == tail) {
            cout << "error\n";
        } else {
            tail = (tail - 1 + MAX_SIZE) % MAX_SIZE;
            cout << arr[tail] << "\n";
        }
    }
    void front() {
        if (head == tail) {
            cout << "error\n";
        } else {
            cout << arr[head] << "\n";
        }
    }
    void back() {
        if (head == tail) {
            cout << "error\n";
        } else {
            cout << arr[(tail - 1 + MAX_SIZE) % MAX_SIZE] << "\n";
        }
    }
    void size() {
        cout << (tail + MAX_SIZE - head) % MAX_SIZE << "\n";
    }
    void clear() {
        head = tail = 0;
        cout << "ok\n";
    }
};

int main() {
    Deque d;
    string command;
    int x;
    while (cin >> command) {
        if (command == "push_front") {
            cin >> x;
            d.push_front(x);
        } else if (command == "push_back") {
            cin >> x;
            d.push_back(x);
        } else if (command == "pop_front") {
            d.pop_front();
        } else if (command == "pop_back") {
            d.pop_back();
        } else if (command == "front") {
            d.front();
        } else if (command == "back") {
            d.back();
        } else if (command == "size") {
            d.size();
        } else if (command == "clear") {
            d.clear();
        } else if (command == "exit") {
            cout << "bye\n";
            break;
        }
    }
    return 0;
}
