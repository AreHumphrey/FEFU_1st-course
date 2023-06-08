#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<class T>
struct Node
{
    Node(T v1, T v2, int v3)
    {
        this->next = NULL;
        this->previous = NULL;
        this->v1 = v1;
        this->v2 = v2;
        this->v3 = v3;
    }

    Node* previous;
    Node* next;
    T v1;
    T v2;
    int v3;
};

template<class T>
struct DEQ
{
private:
    long long count;

    Node<T>* head;
    Node<T>* tail;

public:
    DEQ()
    {
        count = 0;

        head = new Node<T>(' ',' ', 0);
        tail = new Node<T>(' ',' ', 0);

        head->next = tail;
        tail->previous = head;
    }

    void PushBack(T v1, T v2, int v3)
    {
        Node<T>* temp = new Node<T>(v1, v2, v3);

        temp->previous = tail->previous;
        temp->next = tail;

        tail->previous->next = temp;
        tail->previous = temp;

        count++;
    }

    void PushFront(T v1, T v2, int v3)
    {
        Node<T>* temp = new Node<T>(v1, v2, v3);

        temp->next = head->next;
        temp->previous = head;
        head->next->previous = temp;
        head->next = temp;

        count++;
    }

    int PopBack()
    {
        if (count > 0)
        {
            int temp = tail->previous->v3;
            Node<T>* toDelete = tail->previous;
            count--;

            tail->previous = tail->previous->previous;
            tail->previous->next = tail;

            delete toDelete;
            return temp;
        }
        else
        {
            throw "Empty queue";
        }
    }

    int PopFront()
    {
        if (count > 0)
        {
            int temp = head->next->v3;
            Node<T>* toDelete = head->next;
            count--;

            head->next = head->next->next;
            head->next->previous = head;

            delete toDelete;
            return temp;
        }
        else
        {
            throw "Empty queue";
        }
    }

    T First()
    {
        if (count > 0)
            return head->next->v1;
        else
            throw "Empty queue";
    }

    T Last()
    {
        if (count > 0)
            return tail->previous->v1;
        else
            throw "Empty queue";
    }

    long long Count()
    {
        return count;
    }

    bool IsEmpty()
    {
        return count == 0;
    }

    void Clear()
    {
        Node<T>* temp = head->next;
        Node<T>* next;

        while (temp != tail)
        {
            next = temp->next;
            delete temp;
            temp = next;
        }

        head->next = tail;
        tail->previous = head;
        count = 0;
    }

    void Print()
    {
        Node<T>* temp = head->next;
        while (temp != tail)
        {
            cout << temp->v1 << temp->v2 << ' ';
            temp = temp->next;
        }
    }
};

int getIndex(char t1, char t2)
{
    int tt1 = t1 == 'C' ? 0 : t1 == 'S' ? 1 : t1 == 'H' ? 2 : 3;
    int tt2 = t2 == 'A' ? 8 : t2 == 'T' ? 9 : t2 == 'J' ? 10 : t2 == 'Q' ? 11 : t2 == 'K' ? 12 : t2 - '2';
    return tt1 * 13 + tt2;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<bool> ex(48, false);
    string temp;
    int ind;

    DEQ<char> _;

    while (!cin.eof())
    {
        getline(cin, temp);
        if (temp[0] == '+')
        {
            ind = getIndex(temp[1], temp[2]);
            if (ex[ind])
            {
                cout << "ERROR";
                return 0;
            }
            ex[ind] = true;
            _.PushFront(temp[1], temp[2], ind);
        }
        else if (temp[0] == '#')
        {
            ind = getIndex(temp[1], temp[2]);
            if (ex[ind])
            {
                cout << "ERROR";
                return 0;
            }
            ex[ind] = true;
            _.PushBack(temp[1], temp[2], ind);
        }
        else if (temp[0] == '^')
        {
            if (_.Count() == 0)
            {
                cout << "ERROR";
                return 0;
            }
            ex[_.PopFront()] = false;
        }
        else if(temp[0] == '/')
        {
            if (_.Count() == 0)
            {
                cout << "ERROR";
                return 0;
            }
            ex[_.PopBack()] = false;
        }
    }

    if (_.IsEmpty())
        cout << "EMPTY";
    else
        _.Print();

    return 0;
}
