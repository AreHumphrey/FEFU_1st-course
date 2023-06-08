#include <algorithm>
#include <iostream>
#include <vector>

template<class T>
class Node {
public:
    Node *next;
    T value;

    Node(T value) {
        this->next = nullptr;
        this->value = value;
    }

};

template<class T>
class Queue {
public:
    long long count;
    Node<T> *first;
    Node<T> *last;
    Node<T> *middle;

    Queue() {
        count = 0;
        first = nullptr;
        last = nullptr;
        middle = nullptr;
    }

    void Push(T value) {
        auto temp = new Node<T>(value);
        if (count > 0) {
            last->next = temp;
            last = temp;

            if (count % 2 == 0)
                middle = middle->next;
        } else {
            first = temp;
            last = temp;
            middle = temp;
        }
        count++;
    }

    void CoolPush(T value) {
        if (count > 1) {
            auto temp = new Node<T>(value);
            temp->next = middle->next;
            middle->next = temp;

            if (count % 2 == 0)
                middle = temp;

            count++;
        } else {
            Push(value);
        }

    }

    T Pop() {
        T temp = first->value;
        Node<T> *toDelete = first;
        first = first->next;

        if (count % 2 == 0 && count > 1) {
            middle = middle->next;
        } else if (count == 1) {
            middle = nullptr;
        }
        count--;
        delete toDelete;
        return temp;
    }
};

int main() {
    Queue<long long> q;
    char command;
    long long temp;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> command;
        if (command == '+') {
            std::cin >> temp;
            q.Push(temp);
        } else if (command == '-') {
            std::cout << q.Pop() << '\n';
        } else if (command == '*') {
            std::cin >> temp;
            q.CoolPush(temp);
        }
    }
    return 0;
}
