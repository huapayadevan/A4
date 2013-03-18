// BinarySearchTree.h

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>
#include <cstdlib>

#include "Exceptions.h"
#include "BinaryNode.h"

class BinarySearchTree{
private:

	Node *root;
	
	Node* findMin(Node* t) throw (EmptyTree);
	Node* find(int x, Node* t) throw(ItemNotFound);
	Node* insert(int x, Node* t) throw(DuplicateItem);
	Node* removeMin(Node* t) throw(ItemNotFound);
	Node* remove(int x, Node* t) throw(ItemNotFound);
	
public:

	BinarySearchTree() { root = NULL; }						// default constructor	
	BinarySearchTree(int el) { root = new Node(el); }	// constructor
	~BinarySearchTree(){ deleteTree(root); root = NULL; }	// destructor
	
	bool isEmpty() const { return root == NULL; }
	int size() { return (root == NULL)? 0: root->size(root);}		// is this correct?
	int height() { return (root == NULL)? 0: root->height(root);}	// correct?
	
	void insert(int x) throw(DuplicateItem) { root = insert(x, root); }	// call to private "insert" function
	void remove(int x) throw(ItemNotFound) { root = remove(x, root); }		// call to private "remove" function
	Node* find(int x) throw (ItemNotFound) { root = find(x, root); }	// call to private "find" function
	
	void copy(BinarySearchTree& rhs);
	void merge(int rootItem, BinarySearchTree& t1, BinarySearchTree& t2);
	void deleteTree(Node* root);

};

class TreeOperation{	// contains only one pure virtual function:
public: 
	virtual void processNode(int elem) = 0;
};


#endif