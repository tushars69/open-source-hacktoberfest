#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// A utility function to create a new Binary Tree node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// To store the inorder traversal of tree
void storeBSTNodes(Node* root, Node* inorder[], int &len) {
    if (root == nullptr)
        return;

    storeBSTNodes(root->left, inorder, len);

    inorder[len++] = root;

    storeBSTNodes(root->right, inorder, len);
}

// Recursive function to calculate minimum time
int minTime(Node* root, Node* inorder[], int start, int end) {
    if (root == nullptr)
        return 0;

    int len = 0;
    int min_val = INT_MAX;

    // To store nodes of left subtree
    Node* left_inorder[100];
    // To store nodes of right subtree
    Node* right_inorder[100];

    int left_start = start, left_end = -1;
    int right_start = end, right_end = -1;

    for (int i = start; i <= end; i++) {
        if (inorder[i]->data < root->data) {
            left_inorder[++left_end] = inorder[i];
        } else {
            right_inorder[++right_end] = inorder[i];
        }
    }
