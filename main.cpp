/*//////////////////////////////////
//  Benedikt Binger
//////////////////////////////////*/

#include <iostream>

#include "List.h"

#include "tests.h"



int main(int argc, char** argv) {

	Node* tree = createTree(); // []

	insert(tree, 5);
	insert(tree, 3);
	insert(tree, 4);
	insert(tree, 2);
	insert(tree, 7);
	insert(tree, 8);
	insert(tree, 9);
	insert(tree, 10);

	print(tree);
	std::cout << "\n";

	std::cout << "removing\n";
	// remove(tree, search(tree, 4));
	remove(tree, search(tree, 5));

	print(tree);
	std::cout << "\n";

	// Node *res = search(tree, 4);

	return 0;
}