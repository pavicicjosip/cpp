#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	public:
		int n;
		Node* next; Node(int n, Node* N): n(n), next(N) {}
};

class JCPL
{
	protected:
		Node* head{};
		Node* last{};
	public:
		JCPL() {}
		void push_front(int);
		void push_back(int);
		void display();
		bool erase(int);
};

bool JCPL::erase(int x)
{
	Node* iter = head;
	Node* prev = last;
	while(true)
	{
		if(iter->n == x)
		{
			if(iter == head)
			{
				head = iter->next;
				prev->next = iter->next;
				delete iter;
				return true;
			}
			else
			{
				prev->next = iter->next;
				delete iter;
				return true;
			}
			
		}

		if(iter == last)
		{
			return false;
		}
		iter = iter->next;
		prev = prev->next;
	}
}

void JCPL::display()
{
	
	Node* iter = head;
	int br = 0;
	while(iter != head || br != 1)
	{
		if(iter == head)
			br++;
		cout << iter->n << " ";
		iter = iter->next;
	}
	cout << endl;
	
}

void JCPL::push_front(int x)
{
	Node* n = new Node(x, head);
	if(head == nullptr)
		last = n;
	else
	{
		last->next = n;
	}
	head = n;
}

void JCPL::push_back(int x)
{
	Node* n = new Node(x, head);
	if(head == nullptr)
		head = n;
	else
		last->next = n;
	last = n;
}


int main(void)
{	
	JCPL L;
	L.push_back(3);
	L.push_back(2);
	L.push_back(1);

	L.display();
	L.erase(3);
	L.display();
	return EXIT_SUCCESS;
}