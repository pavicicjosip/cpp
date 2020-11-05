#include <iostream>
#include <cstdlib>

using namespace std;

class Stack
{
	protected:
		int top;
		unsigned int size;
		int* container;
	public:
		Stack() = delete;
		Stack(unsigned int x): size(0), top(x) {container = new int[x]; }
		Stack(const Stack& s)
		{
			top = s.top;
			size = s.size;
			container = new int[size];
			for(int i = 0; i < size; i++)
				container[i] = s.container[i];
		}
		~Stack() { delete [] container; }

		bool empty() const { return size == 0; }
		bool full() const { return size == top; }

		void push(int x) { if(!full()) container[size++] = x; }
		int pop() { if(!empty()) return container[--size];  }

		void print() const
		{
			for(int i = 0; i < size; i++)
				cout << container[i] << " " ;
			cout << endl;
		}
};

int main(void)
{
	Stack s(5);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.print();

	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	s.print();
	return EXIT_SUCCESS;
}