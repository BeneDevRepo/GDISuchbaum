#pragma once

using Key = int;

struct Node {
	Node *parent;
	Node *left;
	Node *right;
	Key key;
};

using Tree = Node*&;


// Node creation:
Node* createNode(const Key key);

// List creation:
Node* createTree();

// List insertions:
Node* insert(Tree tree, const Key key); // returns pointer to inserted node

// List traversal:
Node* search(Tree tree, const Key key); // returns nullptr in case of failure ("List-Search'")


// List removal:
// Node* remove(Node *const node); // returns removed node ("List-Delete")
// Node* remove(List &list, const Key key); // returns removed node ("List-Delete")
void transplant(Tree tree, Node *target, Node *newSub);
Node* minimum(Tree tree);
void remove(Tree tree, Node *node);

// List output:
void print(const Node* tree);