#include <iostream>
using namespace std;

// Node structure for AVL tree
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int value) : data(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int get_Height(AVLNode* node) {
        return (node != nullptr) ? node->height : 0;
    }
    int update_Height(AVLNode* node) {
        if (node != nullptr) {
            node->height = 1 + std::max(get_Height(node->left), get_Height(node->right));
        }
        return node->height;
    }

    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        update_Height(y);
        update_Height(x);
        return x;
    }

    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        update_Height(x);
        update_Height(y);
        return y;
    }

    AVLNode* balanceNode(AVLNode* node) {
        update_Height(node);

        int balance = get_Height(node->left) - get_Height(node->right);

        if (balance > 1) {
            if (get_Height(node->left->right) > get_Height(node->left->left)) {
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        } else if (balance < -1) {
            if (get_Height(node->right->left) > get_Height(node->right->right)) {
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }
        return node;
    }

    AVLNode* insert(AVLNode* node, int value) {
        if (node == nullptr) {
            return new AVLNode(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            // Duplicate values are not allowed
            return node;
        }
        return balanceNode(node);
    }

    bool search(AVLNode* node, int value) const {
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
    AVLTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) const {
        return search(root, value);
    }

    void inorderTraversal(AVLNode* node) const {
        if (node != nullptr) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }

    void inorderTraversal() const {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVLTree avl;

    avl.insert(5);
    avl.insert(3);
    avl.insert(8);
    avl.insert(1);
    avl.insert(4);
    avl.insert(7);
    avl.insert(10);

    std::cout << "Is 4 present in the AVL tree? " << (avl.search(4) ? "Yes" : "No") << std::endl;
    std::cout << "Is 6 present in the AVL tree? " << (avl.search(6) ? "Yes" : "No") << std::endl;

    std::cout << "In-order traversal: ";
    avl.inorderTraversal();

    return 0;
}
