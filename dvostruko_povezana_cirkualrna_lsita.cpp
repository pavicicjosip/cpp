#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	public:
		int n;
		Node* prev{};
		Node* next{};
		Node(Node* P, int n, Node* N): prev(P), next(N), n(n) {}
};

class DCPL
{
	protected:
		Node* head{};
		Node* last{};
	public:
		DCPL(){}
		void push_front(int);
		void display();

};
void DCPL::display()
{
	Node* iter = head;
	while(true)
	{
		cout << iter->n << " ";
		if(iter == last)
			break;
		iter = iter->next;
	}
	cout << endl;
}

void DCPL::push_front(int x)
{
	if(head == nullptr && last == nullptr)
	{
		Node* N = new Node(last, x, head);
		head = N;
		last = N;
	}
	else
	{
		Node* N = new Node(last, x, head);
		head->prev = N;
		last->next = N;
		head = N;
	}
}



int main(void)
{	
	DCPL L;
	L.push_front(3);
	L.push_front(2);
	L.push_front(1);
	L.push_front(3);
	L.push_front(2);
	L.push_front(1);
	L.display();

	return EXIT_SUCCESS;
}