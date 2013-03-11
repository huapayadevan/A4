// The purpose of this program is to create a binary search tree, that empirically calculates the average search cost for each node in such a tree
// and removes a designated node

#include <iostream>#include 
#include <fstream>
#include "LinkedQueue.h"
#include "LinkedStack.h"

using namespace std;

// add your functions here

int main(){
try{ 
	
	BinarySearchTree bt;
	// here generate the tree bt with integer elements
	//...
	PrintTreeNode pt;
	bt.getRoot()->preOrderTraversal(pt);	// same as bt.preOrderTraversal(pt);
	cout << endl;
	//...
	}
}

}catch (...){ cerr<< "you glubed up"; }

