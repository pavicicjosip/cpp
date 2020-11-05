#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Node
{
    public:

    Node(Node* n, int d) : n(n), d(d) { }
    Node* n;
    int d;
};

class List
{
    public:

    List() : head(0) { }

    void add(int d)
    {
        head = new Node(head, d);
    }

    void reverse()
    {   
        Node* del;
        queue<int> Q;
        while(head != nullptr)
        {
            Q.push(head->d);
            del = head;
            head = head -> n;
            delete del;
        }
    
        while(!Q.empty())
        {
            add(Q.front());
            Q.pop();
        }
    }

    friend ostream& operator<<(ostream& o, const List l)
    {
        for (Node* n = l.head; n; n = n->n)
            cout << n->d << ' ';
        return o;
    }

    Node* head;
};

int main()
{
    List L;
    for (int n; cin >> n; L.add(n)); // ctrl+d
    L.reverse();
    cout << L;
    return 0;
}
