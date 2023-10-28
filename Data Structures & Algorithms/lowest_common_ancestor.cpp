#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to insert a node into the BST.
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

// Function to find the lowest common ancestor in a BST.
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;

    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

int main() {
    // Construct a BST
    TreeNode* root = nullptr;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);

    // Find the LCA of nodes with values 15 and 35
    TreeNode* p = new TreeNode(15);
    TreeNode* q = new TreeNode(35);

    TreeNode* lca = lowestCommonAncestor(root, p, q);
    if (lca != nullptr) {
        std::cout << "Lowest Common Ancestor: " << lca->val << std::endl;
    } else {
        std::cout << "Lowest Common Ancestor not found." << std::endl;
    }

    return 0;
}
