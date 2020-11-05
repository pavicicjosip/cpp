#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
	protected:
		int n;
		Node* _par;
		Node* _left;
		Node* _right;
	public:
		Node(int n): n(n), _par(nullptr), _left(nullptr), _right(nullptr) {}

		void setLeft(Node* left)  { _left = left; }
    	void setRight(Node* right) { _right = right; }
    	void setParent(Node* par) { _par = par; }

    	int element() { return n; }
	    Node* left() { return _left; }
	    Node* right() { return _right; }
	    Node* parent() { return _par; }

	    bool isRoot() { return _par == nullptr; }
	    bool isLeaf() { return _left == nullptr && _right == nullptr;} 
};

class BinaryTree
{
	public:
		Node* _root;
		unsigned int _size;
	public:
		BinaryTree(): _root(nullptr), _size(0) {}
		~BinaryTree(){}

		Node* root(){ return _root; }
   		unsigned int size() { return _size ; }

		bool addRoot(int);
		bool expandLeaves(Node*, int, int);

		void preorderPrint(Node*);
		void postorderPrint(Node*);
		void inorderPrint(Node*);
		
};

void BinaryTree::inorderPrint(Node* N)
{
	if(N == nullptr)
		return;
	preorderPrint(N->left());
	cout << N->element() << "   ";
	preorderPrint(N->right());
}


void BinaryTree::postorderPrint(Node* N)
{
	if(N == nullptr)
		return;
	preorderPrint(N->left());
	preorderPrint(N->right());
	cout << N->element() << "   ";

}


void BinaryTree::preorderPrint(Node* N)
{
	if(N == nullptr)
		return;
	cout << N->element() << "   ";
	preorderPrint(N->left());
	preorderPrint(N->right());
}

bool BinaryTree::expandLeaves(Node* N, int l, int r)
{
	if(N->left() != nullptr && N->right() != nullptr)
		return false;
	else
	{
		Node* R = new Node(r);
		Node* L = new Node(l);
		R->setParent(N);
		L->setParent(N);
		N->setLeft(L);
		N->setRight(R);

		_size += 2;
		return true;
	}
}

bool BinaryTree::addRoot(int x)
{
	if(_root != nullptr)
		return false;
	else
	{
		_root = new Node(x);
		_size = 1;
		return true;
	}
}

int depth( Node& N)
{
	if(N.isRoot())
		return 0;
	else
		return 1 + depth(*N.parent());
}

int main(void)
{	
	BinaryTree T;
    T.addRoot(1);
    T.expandLeaves(T.root(), 2, 3);
    T.expandLeaves(T.root()->left(), 4, 5);

    T.preorderPrint(T.root());
    cout << endl;
    T.inorderPrint(T.root());
    cout << endl;
    T.postorderPrint(T.root());
    cout << endl;

    cout << depth(*(T.root()->left()->left())) << endl;
	return EXIT_SUCCESS;
}