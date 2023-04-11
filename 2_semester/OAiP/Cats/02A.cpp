#include <fstream>

using namespace std;
class Heap {
private:
    const static int MAX_SIZE = 1000000;
    int HeapArr[MAX_SIZE], size;

public:
    Heap() {
        size = 0;
    }

    int Parent(int), leftChild(int), rightChild(int);

    int Delete(), ShowSize(), ShowMainParent();

    void Insert(int), Sort(int), Swap(int *, int *);
};


int Heap::Parent(int i) {
    return (i - 1) / 2;
}


int Heap::leftChild(int i) {
    return (i * 2) + 1;
}


int Heap::rightChild(int i) {
    return (i * 2) + 2;
}


int Heap::Delete() {
    int max = HeapArr[0];

    HeapArr[0] = HeapArr[size - 1];
    size--;

    Sort(0);

    return max;
}


void Heap::Swap(int *x, int *y) {
    int temp = *x;

    *x = *y;
    *y = temp;
}


void Heap::Sort(int i) {
    int left, right, largest, temp;

    left = Heap::leftChild(i);
    right = Heap::rightChild(i);
    largest = i;

    if (left <= size && HeapArr[left] > HeapArr[largest]) largest = left;

    if (right <= size && HeapArr[right] > HeapArr[largest]) largest = right;

    if (largest != i) {
        temp = HeapArr[i];
        HeapArr[i] = HeapArr[largest];
        HeapArr[largest] = temp;

        Sort(largest);
    }
}


void Heap::Insert(int Number) {
    HeapArr[size] = Number;
    int i = size;
    size++;

    while (i != 0 && HeapArr[Heap::Parent(i)] < HeapArr[i]) {
        Heap::Swap(&HeapArr[Heap::Parent(i)], &HeapArr[i]);
        i = Heap::Parent(i);
    }
}


int Heap::ShowSize() {
    return size;
}


int Heap::ShowMainParent() {
    return HeapArr[0];
}


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int AmountNumbers, Number, Minimal;
    Heap maxHeap, minHeap;

    in >> AmountNumbers;

    for (int i = 0; i < AmountNumbers; i++) {
        in >> Number;

        if (minHeap.ShowSize() != 0) {
            Minimal = -minHeap.ShowMainParent();

            if (Number > Minimal)
                minHeap.Insert(-Number);
            else
                maxHeap.Insert(Number);
        } else {
            maxHeap.Insert(Number);
        }

        while (minHeap.ShowSize() > maxHeap.ShowSize())
            maxHeap.Insert(-minHeap.Delete());
        while (minHeap.ShowSize() + 1 < maxHeap.ShowSize())
            minHeap.Insert(-maxHeap.Delete());

        out << maxHeap.ShowMainParent() << " ";
    }

    return 0;
}
