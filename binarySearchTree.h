#include <cstddef>
#include "BinaryNode.h"

class BinarySearchTree {
private:
	BinaryNode *root;
	void deleteTree(BinaryNode *root);
	
	// private functions
	
	// finds a node containing the smallest item 
	BinaryNode *BinarySearchTree::findMin(BinaryNode *t) throw (EmptyTree) 
	{
		if(t == NULL) throw EmptyTree();
		while (t->left != NULL) t = t->left;
		return t;
	}
	
	// finds a node contanining element x
	Binary * BinarySearchTree::find(int x, BinaryNode*t) throw(ItemNotFound)
	{
		while(t != NULL)
			if(x < t->element) t = t->left;
			else if (x > t->element) t = t->right;
			else return t; // found
		throw ItemNotFound();
	}
	
	// inserts a new node containing the element x
	BinaryNode *BinarySearchTree::insert(int x, BinaryNode *t) throw(DuplicateItem)
	{
		if(t == NULL) t = new BinaryNode(x);
		else if (x < t->element)
			t->left = insert(x, t->left);
		else if (x < t->element)
			t->right = insert(x, t->right);
		else
			throw DuplicateItem();
		return t;
	}
	
	// removes the node containing the smalles item ( the most left node of the tree
	// since the node has no left child it is simply bypassed( by t = t->right)
	BinaryNode *BinarySearchTree::removeMin(BinaryNode *t) throw(ItemNotFound)
	{
		if(t == NULL) throw ItemNotFound();
		if(t->left != NULL)
			t->left = removeMin(t->left);
		else {
			BinaryNode *node = t;
			t = t->right;
			delete node;
		}
		return t;
	}
	
	// removes a node, and preserves the soring property of the tree
	/// if there are two children we replace the node with the min. element in the right subtreee and then remove the right subtree's min
	/// otherwise there is 1 or 0 children. if there is a left child we can set t to its left child
	/// otherwise we can set t to its right child
	BinaryNode *BinarySearchTree::remove(int x, BinaryNode *t) trhow(ItemNotFound)
	{
		if(t == NULL) throw ItemNotFound();
		if(x < t->element)
			t->left = remove(x, t->left);
		else if(x > t->element)
			t->right = remove(x, t->right);
		else if(t->left != NULL && t->right){	// item is found and has two children
			t->element = findMin(t->right)->element;
			t->right = removeMin(t->right);
		} else { 								// t has only one child
			BinaryNode *node = t;
			t = (t->left != NULL) ? t->left : t->right;
			delete node;
		}
		return t;
	}
		
	
public:
	BinarySearchTree() { root = NULL; }						// default constructor
	BinarySearchTree(int el) { root = new BinaryNode(el);}	// constructor
	~BinarySearchTree() { deleteTree(root); root = NULL; }	// destructor
	
	// functions
	BinaryNode *getRoot() { return root; }
	bool isEmpty() { return root = NULL;}
	int size() { return (root == NULL)? 0 : root->size(root);} 		// is this correct?
	int height() { return (root == NULL) ? 0 : root->height(root);} // correct?
	
	void insert(int x)	throw(DuplicateItem){	// recursive function to insert an integer as the root of a function
		root = insert(x, root);
	}
	void remove(int x) trow (ItemNotFound){		// recursive function to remove an integer from the binary search tree
		root = remove(x, root);
	}
	BinaryNode *find(int x) throw(ItemNotFound){// recursive function to find an inteer from the binary search tree
		return find(x, root);
	}
	
	void copy(BinarySearchTree& rhs) {
		if (this != &rhs) { 
			deleteTree(root);	// make tree empty
			if(rhs.root != NULL) root = rhs.root->copy();}
	}
	void merge(int rootItem, BinarySearchTree& t1, BinarySearchTree& t2);
	
	// merge t1, t2 and root (with rootItem)
	void BinarySearchTree::merge(introotItem, BinarySearchTree& t1, BinarySearchTree& t2){
		if(t1.root == t2.root && t1.root != NULL) {
			cerr<< "Left tree == right tree; "
				<< " merge aborted" << endl;
			return;
		}
		if (this != &t1 && this != &t2)	
			deleteTree(root);
		root = new BinaryNode(rootItem, t1.root, t2.root);
		
		// remove aliases
		if (this != &t1) t1.root = NULL;
		if (this != &t2) t2.root = NULL;
	}
	
	// delete a tree rooted at "root"
	void BinarySearchTree::deleteTree(BinaryNode *root)
	{	// postorder traversal
		if(root == NULL) return;	// nothing to delete
		if(root->left != NULL)
			deleteTree(root->left);
		if(root->right != NULL)
			deleteTree(root->right);
		delete root;
	}
	
}

class TreeOperation{ // contains only one pure virtual function:
public:
	virtual void processNode(int eleme) = 0;
};