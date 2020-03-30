#include <iostream>
#include <cstdlib>

using namespace std;

class Node
{
public:
	float key;
	Node* left;
	Node* right;
	Node* parent;

	Node(float x): key(x), left(nullptr), right(nullptr), parent(nullptr) {}
};

class BinarySearchTree
{
public:
	Node* root;

	BinarySearchTree(): root(nullptr) {}
	void tree_insert(Node* n);
};

void BinarySearchTree::tree_insert(Node* n)
{
	Node* y = nullptr;
	Node* x = root;
	while(x != nullptr)
	{
		y = x;
		if( n->key < x->key)
				x = x->left;
		else
				x = x->right;
	}
	n->parent = y;
	if(y == nullptr)
			root = n;       //tree was empty
	else if( n->key < y->key)
		y->left = n;
	else
		y->right = n;
}

//Time required O(h), h -> height of given tree/subtree
//returns the node with the maximum value in the given tree/subtree
Node* tree_maximum(Node* n)
{
	while(n->right != nullptr)
		n = n->right;
	return n;
}

//Time required O(h), h -> height of given tree/subtree
//returns the node with the minimum value in the given tree/subtree
Node* tree_minimum(Node* n)
{
	while(n->left != nullptr)
		n = n->left;
	return n;
}

//Time required O(h), h -> height of given tree/subtree
//returns the node with the successor for n->value in the given tree/subtree
Node* tree_successor(Node* n)
{
	if(n->right != nullptr)
		return tree_minimum(n->right);
	Node* y = n->parent;
	while(y != nullptr && n == y->right)
	{
		n = y;
		y = y->parent;
	}
	return y;
}

//Time required O(h), h -> height of given tree/subtree
//returns the node with the predecessor for n->value in the given tree/subtree
Node* tree_predecessor(Node* n)
{
	if(n->left != nullptr)
		return tree_maximum(n->left);
	Node* y = n->parent;
	while(y != nullptr && n == y->left)
	{
		n = y;
		y = y->parent;
	}
	return y;
}

//Time required O(h), h -> height of given tree/subtree
//returns a pointer to the node with that given value or returns NULL
Node* tree_search(Node* n, float value)
{
	if(n == nullptr || value == n->key)  
		return n;
	if(value < n->key)
		return tree_search(n->left, value);
	else
		return tree_search(n->right, value);
}

void transplant(BinarySearchTree T, Node* u, Node* v)
{
	if( u->parent == nullptr)
		T.root = v;
	else if( u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if(v != nullptr)
		v->parent = u->parent;
}

void tree_delete(BinarySearchTree T, Node* n)
{
	if(n->left == nullptr)
		transplant(T, n, n->right);
	else if(n->right == nullptr)
		transplant(T, n, n->left);
	else
	{
		Node* y = tree_minimum(n->right);
		if(y->parent != n)
		{
			transplant(T, y, y->right);
			y->right = n->right;
			y->right->parent = y;
		}
		transplant(T, n, y);
		y->left	 = n->left;
		y->left->parent = y;
	}
}

//print tree/subtree
//Time required Θ(n) 
void inorder_tree_walk(Node* n)
{
	if(n != nullptr)
	{
		inorder_tree_walk(n->left);
		cout << n-> key << " ";
		inorder_tree_walk(n->right);
	}
}

int main(void)
{
	BinarySearchTree T;
	Node* n0 = new Node(17);
	Node* n1 = new Node(27);
	Node* n2 = new Node(13);
	Node* n3 = new Node(1);
	Node* n4 = new Node(15);

	T.tree_insert(n0);
	T.tree_insert(n1);
	T.tree_insert(n2);
	T.tree_insert(n3);
	T.tree_insert(n4);

    inorder_tree_walk(T.root);
    cout << endl;

    cout << "Tree search 5: " << tree_search(T.root, 5) << endl;
    cout << "Tree search 13: " << tree_search(T.root, 13)->key << endl;

	cout << "Tree minimum: " << tree_minimum(T.root)->key << endl;
	cout << "Tree maximum: " << tree_maximum(T.root)->key << endl;

	cout << "Tree successor of node 13: " << tree_successor( n2)->key << endl;		
	cout << "Tree predecessor of node 15: " << tree_predecessor( n4)->key << endl;		

	tree_delete(T, n2);
	inorder_tree_walk(T.root);
	cout << endl;

	return EXIT_SUCCESS;
}