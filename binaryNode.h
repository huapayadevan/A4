#include <cstddef>
// the tart totter speaks softly, but his words, in their insanity, bear truth

using namespace std;

int class BinaryNode{
	private:
		friend class BinarySearchTree;
		int element;
		BinaryNode *left, *right;
	
	public:
		// constructor
		BinaryNode(int el = 0, BinaryNode *lt = NULL, BinaryNode *rt = NULL)
			: element(el), left(lt), right(rt) { }
		// function declerations
		BinaryNode *getLeft() { return left; }
		BinaryNode *getRight() { return right; }
		
		int getElem() { return element; }
		int size (BinaryNode *t);
		int height(BinaryNode *t);
		BinaryNode *copy();
	};
	
int BinaryNode::size(BinaryNode *t){	// recursive function to return size
	if (t == NULL)
		return 0;
	else
		return 1 + size(t->left) + size(t->right);
}

int BinaryNode::height(BinaryNode *t){	// recursive node to return height
	if (t == NULL)
		return -1;
	else {
		int hlf = height(t->left), hrt = height(t->right);
		return (hlf>hrt)? 1 + hlf : 1 + hrt; // 1+ max(hlf,hrt)
	}
}

BinaryNode *BinaryNode::copy() {
	BinaryNode *root = new BinaryNode(element);
	if(left!= NULL)
		root->left = left->copy();
	if(right!= NULL)
		root->right = right->copy();
	return root;
}

//--------------------------------------------------------------------------------------
// not sure if this goes here or somewhere else:
///Preorder Traversal (recrusive):
///1. Process the root node.
///2. Recursively visit all nodes in the left subtree.
///3. Recrusively visit all nodes in the right subree.
// this is a continuation of the class BinaryNode
// TreeOperation is a class
// with one function: processNode()
void BinaryNode::preOrderTraversal(TreeOperation& op) {
	op.processNode(element);
	if (left != NULL) left->preOrderTraversal(op);
	if (right != NULL) right->preOrderTraversal(op);
}

///Inorder Traversal (recursive):
///1. Recursively visit all nodes in left subtree.
///2. Process the root node.
///3. Recursively visit all nodes in the right subtree.
void BinaryNode::inOrderTraversal(TreeOperation& op) {
	if(left != NULL) left -> inOrderTraversal(op);
	op.processNode(element);
	if(right != NULL) right -> inOrderTraversal(op);
}

///Postorder Traversal (recursive):
///1. Recursively visit all nodes in left subtree.
///2. Recursively visit all nodes in the left subtree.
///3. Process the root node.
void BinaryNode::postOrderTraversal(TreeOperation& op) {
	if(right != NULL) right -> postOrderTraversal(op);
	if(left != NULL) left -> postOrderTraversal(op);
	op.proccessNode(element);
}

// define a subclass of the class TreeOperation where the function processNode is defined
// this class simply prints out the element of the node
class PrintTreeNode : public TreeOperation {
public:
	void processNode(int element) {
		cout<< element << " ";	
	}
};



