// insertList.c
// programming  pearls charpt 13.2
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX_VALUE 100000
class Node
{
public:
    Node(int v, Node* p);

    int value;
    Node* next;
};

Node::Node(int v, Node* p)
{
    value = v;
    next = p;
}

class IntSetList
{
    int n;
    Node* head;
public:
    IntSetList()
    {
        head = new Node(MAX_VALUE, NULL);
        n = 0;
    }
    void print()
    {
        Node *p = head;
        while (p)
        {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
    void insert(int t)
    {
        head = rinsert(head, t);
    }
    Node* rinsert(Node* p, int t)
    {
        if (p->value < t)
        {
            p->next = rinsert(p->next, t);
        }
        else if (p->value > t)
        {
            Node* cur = new Node(t, p);
            p = cur;
            n++;
        }
        return p;
    }
};

int main()
{
    int i, v;
    IntSetList s;
    for (i = 0; i < 10; i++)
    {
        v = rand() % 100;
        cout << v << " ";
        s.insert(v);
    }
    cout << endl;
    cout << "print IntSetList:\n";
    s.print();
}
