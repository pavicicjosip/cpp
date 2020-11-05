#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	public:
		int n;
		Node* prev = nullptr;
		Node* next = nullptr;
		Node(Node* P, int n, Node* N): prev(P), next(N), n(n) {}
};

class DPL
{
	protected:
		Node* head = nullptr;
		Node* tail = nullptr;
	public:
		DPL() {}
		void push_front(int);
		void display();
};

void DPL::display()
{
	Node* iter = head;
	while( true )
	{
		cout << iter->n << " ";
		if(iter == tail)
			break;
		iter = iter->next;
	}
	cout << endl;
}

void DPL::push_front(int x)
{
	if(head == nullptr && tail == nullptr)
	{
		Node* N = new Node(nullptr, x, nullptr);
		head = N;
		tail = N;
	}
	else
	{
		Node* N = new Node(nullptr , x, head);
		head->prev = N;
		head = N;
 	}
}


int main(void)
{	
	DPL L;
	L.push_front(3);
	L.push_front(2);
	L.push_front(1);
	L.display();

	return EXIT_SUCCESS;
}