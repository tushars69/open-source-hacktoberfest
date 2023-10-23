#include <iostream>
#include <queue>
#include <map>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() : root(nullptr) {}

    void topView() {
        if (!root)
            return;

        std::map<int, int> topViewMap;
        std::queue<std::pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* current = q.front().first;
            int hd = q.front().second;
            q.pop();

            if (topViewMap.find(hd) == topViewMap.end()) {
                topViewMap[hd] = current->data;
            }

            if (current->left) {
                q.push({current->left, hd - 1});
            }

            if (current->right) {
                q.push({current->right, hd + 1});
            }
        }

        for (const auto& pair : topViewMap) {
            std::cout << pair.second << " ";
        }
        std::cout << std::endl;
    }

    void bottomView() {
        if (!root)
            return;

        std::map<int, int> bottomViewMap;
        std::queue<std::pair<Node*, int>> q;

        q.push({root, 0});

        while (!q.empty()) {
            Node* current = q.front().first;
            int hd = q.front().second;
            q.pop();

            bottomViewMap[hd] = current->data;

            if (current->left) {
                q.push({current->left, hd - 1});
            }

            if (current->right) {
                q.push({current->right, hd + 1});
            }
        }

        for (const auto& pair : bottomViewMap) {
            std::cout << pair.second << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->right = new Node(4);
    tree.root->left->right->right = new Node(5);
    tree.root->left->right->right->right = new Node(6);

    std::cout << "Top View: ";
    tree.topView();

    std::cout << "Bottom View: ";
    tree.bottomView();

    return 0;
}
