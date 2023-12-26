#include <iostream>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    bool search(TreeNode* node, int value) const {
        if (node == nullptr) {
            return false;
        }
        if (value == node->data) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) const {
        return search(root, value);
    }
};

int main() {
    // Create a sample binary search tree
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(1);
    bst.insert(4);
    bst.insert(7);
    bst.insert(10);

    // Search for values
    cout << "Is 4 present in the BST? " << (bst.search(4) ? "Yes" : "No") << endl;
    cout << "Is 6 present in the BST? " << (bst.search(6) ? "Yes" : "No") << endl;

    return 0;
}