// BinaryNode.h

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <iostream>

class Node {
private:
	friend class BinarySearchTree;
	// element members
	int element;
	int key;
	Node *parent;
	Node *left;
	Node *right;
	
public:
	
	Node(int el = 0, Node *lt = NULL, Node *rt = NULL)
			: element(el), left(lt), right(rt) { }
	/*// constructors
	Node() : element(0), parent(NULL), left(NULL), right(NULL), key(0) {}		// constructor
	Node(int q) : element(q), parent(NULL), left(NULL), right(NULL), key(0){}
	Node(int q, Node *n1, int k) : element(q), parent(n1), left(NULL), right(NULL), key(k) {}
	Node(int q, Node *n1, Node *n3, Node *n4, int k) : element(q), parent(n1), left(n3), right(n4), key(k) {}
	*/
	// copy constructor
	Node(const Node& temp) {
		element = temp.element;
		parent = temp.get_parent();
		left = temp.get_left();
		right = temp.get_right();
	}	
	
	// get functions
	int get_elem() const;
	int get_key() const;
	Node* get_parent() const;
	Node* get_left() const;
	Node* get_right() const;
	int size (Node *t);
	int height(Node *t);
		
	// modifications functions
	void set_elem(int q);
	void set_key(int q);
	void set_parent(Node *n);
	void set_left(Node *n);
	void set_right(Node *n);
	
	// query functions
	bool is_root() const;
	bool is_extern() const;
	
	// copy constructor?
	Node* copy();
};
	
#endif
	
	