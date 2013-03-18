// BinaryTree.h

#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <vector>

#include "BinaryNode.h"

class BinaryTree{
private:

	Node *root;
	
public:
	
	BinaryTree() : root(NULL) {} // default constructor
	BinaryTree(Node * n) : root(n) {}
	
	//add element