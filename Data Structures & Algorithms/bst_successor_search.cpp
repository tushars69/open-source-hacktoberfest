#include <iostream>

// Define the structure of a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
};

// Function to find the minimum node in a BST
Node* findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Function to find the successor of a node in a BST
Node* findSuccessor(Node* root, Node* node) {
    // If the given node has a right subtree
    if (node->right != nullptr) {
        return findMin(node->right);
    }

    // If the given node does not have a right subtree
    Node* successor = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(7);
    root->left->right->left = new Node(12);

    // Set parent pointers for easier successor calculation
    root->left->parent = root;
    root->right->parent = root;
    root->left->left->parent = root->left;
    root->left->right->parent = root->left;
    root->left->left->left->parent = root->left->left;
    root->left->left->right->parent = root->left->left;
    root->left->right->left->parent = root->left->right;

    Node* node = root->left->right; // Node with data 15

    Node* successor = findSuccessor(root, node);
    if (successor) {
        std::cout << "Successor of " << node->data << " is " << successor->data << std::endl;
    } else {
        std::cout << "No successor found for " << node->data << std::endl;
    }

    return 0;
}
