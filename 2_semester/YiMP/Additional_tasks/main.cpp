#include <iostream>
#include <time.h>

using namespace std;
struct Node;
Node* createNode(int data);
Node* insert(Node* head, int data);
void printList(Node* head);

int main() {
    srand(time(NULL));
    Node* head = nullptr;
    int n;
    cout << "Count elements: \n";
    cin >> n;
    cout << endl;

    int arr[n];
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 20 + (-3);
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        head = insert(head, arr[i]);
//        sortByAsc(head);
    }
    printList(head);
    return 0;
}
struct Node {
    int data;
    Node* next;
};
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}
Node* insert(Node* head, int data) {
    if (!head) return createNode(data);
    if (data < head->data) {
        Node* newNode = createNode(data);
        newNode->next = head;
        return newNode;
    }
    head->next = insert(head->next, data);
    return head;
}
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}