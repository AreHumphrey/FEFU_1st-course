#include <iostream>


struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    int n, k;
    std::cin >> n >> k;
    k--;
    Node *head = new Node(1);
    Node *tail = head;
    for (int i = 2; i <= n; i++) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    tail->next = head;
    Node *curr = head;
    while (n > 1) {

        for (int i = 1; i < k; i++) {

            curr = curr->next;

        }
        Node *temp = curr->next;
        curr->next = temp->next;
        std::cout << temp->data << " ";
        delete temp;
        curr = curr->next;
        n--;
    }
    std::cout << curr->data;


}
