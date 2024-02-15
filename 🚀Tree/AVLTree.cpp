#include <iostream>
#include <algorithm>

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

class AVL {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (node == NULL)
            return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

//perform rotation 
        x->right = y;
        y->left = T2;

//update height
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {

        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + std::max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + std::max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    AVLNode* insertRecursive(AVLNode* root, int value) {
        if (root == nullptr)
            return new AVLNode(value);

        if (value < root->data)
            root->left = insertRecursive(root->left, value);
        else if (value > root->data)
            root->right = insertRecursive(root->right, value);
        else
            return root; // Duplicate keys not allowed

        root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));

        int balance = getBalanceFactor(root);

        if (balance > 1 && value < root->left->data) // Left Left Case
            return rotateRight(root);

        if (balance < -1 && value > root->right->data) // Right Right Case
            return rotateLeft(root);

        if (balance > 1 && value > root->left->data) { // Left Right Case
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }

        if (balance < -1 && value < root->right->data) { // Right Left Case
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inorderTraversal(AVLNode* root) {
        if (root != nullptr) {
            inorderTraversal(root->left);
            std::cout << root->data << " ";
            inorderTraversal(root->right);
        }
    }

public:
    AVL() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void inorder() {
        inorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    AVL avl;
    avl.insert(9);
    avl.insert(5);
    avl.insert(10);
    avl.insert(0);
    avl.insert(6);
    avl.insert(11);
    avl.insert(-1);
    avl.insert(1);
    avl.insert(2);

    std::cout << "Inorder traversal of AVL tree: ";
    avl.inorder();

    return 0;
}
