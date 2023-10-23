#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node at the beginning of the linked list
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to reverse the linked list using recursion
    Node* reverse(Node* current) {
        // Base case: If the current node is the last node (or NULL), return it
        if (current == nullptr || current->next == nullptr) {
            return current;
        }

        // Recursively reverse the rest of the linked list
        Node* restReversed = reverse(current->next);

        // Make the current node the new tail by updating its next pointer
        current->next->next = current;
        current->next = nullptr;

        // Return the new head of the reversed list
        return restReversed;
    }
};

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    LinkedList list;
    list.push(1);
    list.push(2);
    list.push(3);
    list.push(4);

    std::cout << "Original Linked List: ";
    printList(list.head);

    list.head = list.reverse(list.head);

    std::cout << "Reversed Linked List: ";
    printList(list.head);

    return 0;
}
