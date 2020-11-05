#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	public:
		int n;
		Node* next;
		Node(int n, Node* N): n(n), next(N) {}
};

class List
{
	protected:
		Node* head = nullptr;
	public:
		List(){}
		void push_front(int);
		void display();
		Node* search(int);
		bool erase(int);
		unsigned int size();
		~List();
};

unsigned int List::size()
{
	unsigned int br = 0;
	Node* iter = head;
	while(iter != nullptr)
	{
		iter = iter->next;
		br++;
	}
	return br;
}

bool List::erase(int x)
{
	Node* iter = head;
	Node* prev = head;
	while(iter != nullptr)
	{
		if(head->n == x)
		{
			Node* b = head;
			head = head->next;
			delete b;
			return true;
		}
		else if(iter->n == x)
		{
			prev->next = iter->next;
			delete iter;
			return true;
		}
		prev = iter;
		iter = iter->next;
	}
	return false;
}

Node* List::search(int x)
{
	Node* iter = head;
	while(iter != nullptr)
	{
		if(iter->n == x)
			return iter;
		iter = iter->next;
	}
	return nullptr;
}

List::~List()
{
	Node* b;
	Node* iter = head;
	while(iter != nullptr)
	{
		b = iter;
		iter = iter->next;
		delete b;
	}
}

void List::push_front(int x)
{
	Node *n = new Node(x, head);
	head = n;
}

void List::display()
{
	Node* iter = head;
	while(iter != nullptr)
	{
		cout << iter->n << " ";
		iter = iter->next;
	}
	cout << endl;
}


int main(void)
{
	List L;
	L.push_front(4);
	L.push_front(7);
	L.push_front(9);
	L.display();
	cout << L.search(3) << endl;
	cout << L.erase(9) << endl;
	L.display();
	cout << L.size() << endl;


	return EXIT_SUCCESS;
}