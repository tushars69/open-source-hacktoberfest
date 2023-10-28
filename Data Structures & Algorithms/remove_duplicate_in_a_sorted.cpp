#include <iostream>

// Definition for a singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove duplicates from a sorted linked list.
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;
    
    while (current != nullptr && current->next != nullptr) {
        if (current->val == current->next->val) {
            // Duplicate found, remove the next node.
            ListNode* duplicate = current->next;
            current->next = duplicate->next;
            delete duplicate;
        } else {
            // Move to the next node.
            current = current->next;
        }
    }
    
    return head;
}

// Function to print the linked list.
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create a sorted linked list with duplicates.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    
    std::cout << "Original List: ";
    printList(head);

    // Remove duplicates.
    head = deleteDuplicates(head);

    std::cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
