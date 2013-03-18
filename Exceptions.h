// Exceptions to be used with BinaryNode and BinarySearchTree
#include <string>
#include <stdexcept>

using namespace std;

struct EmptyTree : std::runtime_error{
	EmptyTree() : runtime_error("Empty Tree \n"){}
};

struct ItemNotFound : std::runtime_error {
	ItemNotFound() : runtime_error("Item Not Found \n"){}
};

struct DuplicateItem : std::runtime_error {
	DuplicateItem() : runtime_error("Duplicate Item Found \n") {}
};

