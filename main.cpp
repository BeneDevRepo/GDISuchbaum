#include <iostream>

#include "SearchTree.hpp"


int main(int argc, char** argv) {
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

	std::cout << "removing element before 5 (3)\n";
	tree.deleteNode(tree.search(5)->predecessor());
	std::cout << tree << "\n";

	std::cout << "removing element after 5 (7)\n";
	tree.deleteNode(tree.search(5)->successor());
	std::cout << tree << "\n";

	return 0;
}