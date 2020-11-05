#include <iostream>
#include <cstdlib>

using namespace std;

class Queue
{
	protected:
		unsigned int size, head, tail;
		int* container;
	public:
		Queue() = delete;
		Queue(unsigned int x): size(x), head(0), tail(0) { container = new int[x]; }
		Queue(const Queue& q)
		{
			size = q.size;
			head = q.head;
			tail = q.tail;
			container = new int[size];
			for(int i = head; i < tail; i++)
				container[i] = q.container[i];
		}
		~Queue() { delete [] container; }

		bool empty() const { return tail == head; }
		bool full() const { return tail == size; }

		void enqueue(int); 
		int dequeue();

		void print() const
		{
			for(int i = 0; i < tail; i++)
				cout << container[i] << " ";
			cout << endl;
		}

};

void Queue::enqueue(int x)
{
	if(!full())
		container[tail++] = x;
}

int Queue::dequeue()
{
	if(~empty())
	{
		int r = container[head];
		for(int i = 0; i < tail; i++)
			container[i] = container[i+1];
		tail--;
		return r;
	}
}


int main(void)
{
	Queue q(3);
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	Queue e = q;
	q.print();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.print();
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.empty() << endl;
	e.print();
	return EXIT_SUCCESS;
}