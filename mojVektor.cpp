#include <iostream>
#include <cstdlib>

using namespace std;

class MojVektor
{
	public:
		int *P;
		int _size;
		int _capacity;
	public:
		MojVektor(int n)
	    {
	        P = new int[n];
	        _capacity = n;
	        _size = 0;
	    }
		MojVektor(const MojVektor& v)
		{
			P = new int[v._capacity];
			_capacity = v._capacity;
			_size = v._size;
			for(int i = 0; i < _size; i++)
				P[i] = v.P[i];
		}
		bool push_back(int);
		int* search(int);
		void print() const;
		int capacity() const { return _capacity; }
		int size() const { return _size; }
		void operator=(const MojVektor&);

		~MojVektor()
		{
			delete [] P;
		}
};

void MojVektor::operator=(const MojVektor& v)
{
	if(P!=nullptr)
		delete [] P;
	_size = 0;
	_capacity = 0;
	P = new int[v.capacity()];
	_capacity = v.capacity();
	_size = v.size();
	for(int i = 0; i < _size; i++)
		P[i] = v.P[i];
}

void MojVektor::print() const 
{
	for(int i = 0; i < _size; i++)
		cout << P[i] << " ";
	cout << endl;
}

int* MojVektor::search(int x)
{
	for(int i = 0; i < _size; i++)
		if(P[i] == x)
			return &P[i];
		else
			return nullptr;
}

bool MojVektor::push_back(int x)
{
	if(_size < _capacity){
		P[_size++] = x;
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	MojVektor v(3);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);  // 4 will not get in. Why?
    v.print();
    if (v.search(4) != nullptr)
        cout << "element found" << endl;
    else
        cout << "element not found" << endl;

    MojVektor v1 = v; // copy-constructor called!
    v1.print();

	return EXIT_SUCCESS;
}