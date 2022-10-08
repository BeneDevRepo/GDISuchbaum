#pragma once

#include <iostream>


template<typename T>
class TreeNode {
	using Node = TreeNode<T>;

private:
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;

public:
    const T key;

private:
    void transplant(const Node *const nodeToReplace, Node *const replacement); // internally used by void delete_node(...)

public:
    TreeNode(const T rootKey): key(rootKey) { }
    virtual ~TreeNode() {
        delete this->left;
        delete this->right;
    }

	// Disallow copying:
    TreeNode(const Node& copyFrom) = delete;
    Node& operator=(const Node& copyFrom) = delete;

	// Disallow moving:
    TreeNode(Node&& moveFrom) = delete;
    Node& operator=(Node&& moveFrom) = delete;

public:
    Node* insert(const T key);
    void deleteNode(Node *const nodeToDelete);

    Node* search(const T key);

    Node* minimum();
    Node* maximum();

    Node* predecessor();
    Node* successor();

public:
	// optional, nicht teil der Kern-API (aber praktisch zum debuggen):
	friend std::ostream& operator<<(std::ostream& cout, const Node* tree) {
		if(tree == nullptr) return cout; // nothing to print

		cout << tree->left << tree->key << ", " << tree->right;

		return cout;
	}

	friend std::ostream& operator<<(std::ostream& cout, const Node& tree) {
		cout << &tree;

		return cout;
	}
};

#include "SearchTree_impl.hpp"