/*//////////////////////////////////
//  Benedikt Binger
//////////////////////////////////*/

#include <iostream>

#include "SearchTree.hpp"


int main(int argc, char** argv) {
	// TreeNode<int>* tree = new TreeNode<int>(5);
	TreeNode<int> tree(5);

	tree.insert(3);
	tree.insert(4);
	tree.insert(2);
	tree.insert(7);
	tree.insert(8);
	tree.insert(9);
	tree.insert(10);

	std::cout << tree << "\n";

	std::cout << "removing 4\n";
	tree.deleteNode(tree.search(4));
	std::cout << tree << "\n";

	std::cout << "removing 8\n";
	tree.deleteNode(tree.search(8));
	std::cout << tree << "\n";

	std::cout << "removing 10\n";
	tree.deleteNode(tree.search(10));
	std::cout << tree << "\n";

	return 0;
}