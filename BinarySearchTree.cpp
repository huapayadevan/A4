// Binary Search Tree .cpp

#include "BinarySearchTree.h"

using namespace std;

///---private functions--------------------------------------------------

// finds a node containing the smallest item
Node* BinarySearchTree::findMin(Node *t) throw (EmptyTree)
{
	if(t == NULL) throw EmptyTree();
	while (t->left !=NULL) t = t->left;
	return t;
}

// finds a node containing element x
Node* BinarySearchTree::find(int x, Node* t) throw (ItemNotFound)
{
	while(t != NULL)
		if(x < t->element) t = t->left;
		else if (x > t->element) t = t->right;
		else return t;	// found
	throw ItemNotFound();
}

// removes the noe containing the smallest item (the left most node of the tree
// since the node has no left child it is simply bypassed ( by t = t->right)
Node* BinarySearchTree::removeMin(Node *t) throw(ItemNotFound)
{
	if(t == NULL) throw ItemNotFound();
	if(t->left != NULL)
		t->left = removeMin(t->left);
	else{
		Node *node = t;
		t = t->right;
		delete node;
	}
	return t; 
}

// removes a node and preserves the sorting perty of the tree
/// if there are two childrenn we replace the node with the min. element in the right subntree and then remove the right subtree's min
/// otherwise there is 1 or 0 children. if there is a left child we can set t to its left child
/// othrwise we can set t to its right child
Node* BinarySearchTree::remove(int x, Node *t) throw(ItemNotFound)
{
	if(t == NULL) throw ItemNotFound();
	if(x < t->element)
		t->left = remove(x, t->left);
	else if (x > t->element)
		t->right = remove(x, t->right);
	else if(t-> left != NULL && t->right != NULL){
		t->element = findMin(t->right)->element;
		t->right = removeMin(t->right);
	} else {
		Node *node = t;
		t = (t->left != NULL) ? t->left : t->right;
		delete node;
	}
	return t;
}

///---public functions--------------------------------------------------

void BinarySearchTree::copy(BinarySearchTree& rhs)
{
	if(this != &rhs) {
		deleteTree(root);	// make tree empty
		if(rhs.root != NULL) root = rhs.root->copy();	// copy the tree
		}
}

// merge t1, t2, and root (with rootitem)
void BinarySearchTree::merge(int rootItem, BinarySearchTree& t1, BinarySearchTree& t2)
{
	if(t1.root == t2.root && t1.root != NULL) {
		cerr<< "Left tree == Right tree; "
			<< "merge aborted" << endl;
		return;
	}
	if (this != &t1 && this != &t2)
		deleteTree(root);
	root = new Node(rootItem, t1.root, t2.root);
	
	// remove aliases
	if (this != &t1) t1.root = NULL;
	if (this != &t2) t2.root = NULL;
}

// delete a tree rooted at "root"
void BinarySearchTree::deleteTree(Node*root)
{
	//postorder traversal
	if(root == NULL) return;	// nothing to delete
	if(root->left != NULL)		
		deleteTree(root->left);	// recursive call to delete left subtree
	if(root->right != NULL)
		deleteTree(root->right);// recursive call to delete right subtree
	delete root;				// delete the root
}




















	
