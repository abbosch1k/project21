#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

class BST {
    Node* root = nullptr;

    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

public:
    void add(int value) {
        root = insert(root, value);
    }

    void print() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    tree.add(5);
    tree.add(2);
    tree.add(8);
    tree.add(1);
    tree.print();
}
