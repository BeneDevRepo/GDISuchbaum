#include "List.h"

#include <iostream>



//////////////////////////////
// Node creation:
//////////////////////////////

Node* createNode(const Key key) {
	Node *out = new Node{};
	out->key = key;
	return out;
}



//////////////////////////////
// List creation:
//////////////////////////////

Node* createTree() {
	return nullptr;
}



//////////////////////////////
// List insertions:
//////////////////////////////

Node* insert(Tree tree, const Key key) {
	Node *const node = new Node{
		.key = key,
		.left = nullptr,
		.right = nullptr,
		.parent = nullptr
	};

	// Tree-Insert(T, z)
	Node *y = nullptr;
	Node *x = tree;
	while (x != nullptr) {
		y = x;
		if (node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}

	node->parent = y;
	if (y == nullptr)
		tree = node; // Baum T war leer
	else if (node->key < y->key)
		y->left = node;
	else
		y->right = node;

	return node;
}




//////////////////////////////
// List traversal:
//////////////////////////////

Node* search(Tree tree, const Key key) {
	if(tree == nullptr || key == tree->key)
		return tree;
	if(key < tree->key)
		return search(tree->left, key);
	return search(tree->right, key);
}


//////////////////////////////
// List removal:
//////////////////////////////

// Node* remove(Node *const node) {
// 	node->parent->left = node->left;
// 	node->left->parent = node->parent;
// 	return node;
// }

void transplant(Tree tree, Node *target, Node *newSub) {
	if(target->parent == nullptr)
		tree = newSub;
	else if(target == target->parent->left)
		target->parent->left = newSub;
	else
		target->parent->right = newSub;

	if(newSub != nullptr)
		newSub->parent = target->parent;
}

Node* minimum(Tree tree) {
	for(Node *min = tree;; min = min->left)
		if(min->left == nullptr)
			return min;
}

void remove(Tree tree, Node *node) {
	if(node->left == nullptr) {
        transplant(tree, node, node->right);
    }

    else if(node->right == nullptr) {
        transplant(tree, node, node->left);
    }

    else {
        Node* min = minimum(node->right);

        if(min->parent != node) {
            transplant(tree, min, min->right);
            min->right = node->right;
            min->right->parent = min;
        }

        transplant(tree, min, node);
        min->left = node->left;
        min->left->parent = min;
    }
}


//////////////////////////////
// List output:
//////////////////////////////

void print(const Node* tree) {

	// for(Node *current = list.nil->left; current != list.nil; current = current->left)
	// 	printf("> %d ", current->key);


	if(tree != nullptr) {
		print(tree->left);
		std::cout << tree->key << ", ";
		print(tree->right);
	}
}