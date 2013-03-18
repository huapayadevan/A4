// BinaryNode.cpp

#include "BinaryNode.h"

using namespace std;

// get function definitions
int Node::get_elem() const { return element; }
int Node::get_key() const {	return key; }
Node* Node::get_parent() const{	return parent; }
Node* Node::get_left() const{ return left; }
Node* Node::get_right() const{ return right; }


// set functions definitions
void Node::set_elem(int q){	element = q; }
void Node::set_key(int q) { key = q; }
void Node::set_parent(Node *n) { parent = n; }
void Node::set_left(Node *n) { left = n; }
void Node::set_right(Node *n) { right = n; }


// boolean funcitons

// returns true if node is the root
bool Node::is_root() const{
	return (get_parent() == NULL)?  true: false;
}

// returns true if node is external node
bool Node::is_extern() const {
	if((get_left() == NULL) && (get_right() == NULL)){
		return true;
	} else return false;
}

// returns size of Node
int Node::size(Node *t){	// recursive function to return size
	if (t == NULL)
		return 0;
	else
		return 1 + size(t->left) + size(t->right);
}

int Node::height(Node *t){	// recursive node to return height
	if (t == NULL)
		return -1;
	else {
		int hlf = height(t->left), hrt = height(t->right);
		return (hlf>hrt)? 1 + hlf : 1 + hrt; // 1+ max(hlf,hrt)
	}
}

Node* Node::copy() {
	Node *root = new Node(element);
	if(left!= NULL)
		root->left = left->copy();
	if(right!= NULL)
		root->right = right->copy();
	return root;
}

int main() {

	cout<< "runs";
}




