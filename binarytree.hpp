// When creating new TreeNode's: Use new instead of malloc!

template<typename T>
class TreeNode {
    TreeNode<T>* father = nullptr;
    const T key;
    TreeNode<T>* left = nullptr;
    TreeNode<T>* right = nullptr;

    // internally used by void delete_node(...)
    void transplant(TreeNode<T>* nodeToReplace, TreeNode<T>* replacementNode);

public:
    TreeNode<T>* search(const T key);
    TreeNode<T>* minimum();
    TreeNode<T>* maximum();
    TreeNode<T>* insert(const T key);
    TreeNode<T>* predecessor();
    TreeNode<T>* successor();

    /*  
        The pointer passed as parameter is merely for the purposes of identifying the node within this tree
        If the parameter is nullptr or not contained within this (sub-)tree, this function should change nothing.

        After deletion, this method returns a pointer to this node or to it's replacement if this node deleted itself
        If nullptr is returned, the tree is empty
        
        It should be called in a line similar to this:
        treeRoot = treeRoot->deleteNode(nodeToDelete); // nodeToDelete may equal treeRoot
    */
    TreeNode<T>* deleteNode(const TreeNode<T>* const nodeToDelete);

    TreeNode(const T rootKey) : key(rootKey) {}
    virtual ~TreeNode() {
        delete this->left;
        delete this->right;
    }

    // Disallow (accidental) copying or moving
    TreeNode(const TreeNode<T>& copyFrom) = delete;
    TreeNode(TreeNode<T>&& moveFrom) = delete;
};