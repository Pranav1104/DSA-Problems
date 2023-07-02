#include <iostream>

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(); 
        ListNode *temp = dummy; 
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry) {
            int sum = carry; 
            
            if (l1 != nullptr) {
                sum += l1->val; 
                l1 = l1->next; 
            }
            
            if (l2 != nullptr) {
                sum += l2->val; 
                l2 = l2->next; 
            }
            
            carry = sum / 10; 
            ListNode *node = new ListNode(sum % 10); 
            temp->next = node; 
            temp = temp->next; 
        }
        
        return dummy->next; 
    }
};

// Function to create a new ListNode
ListNode* createNode(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = nullptr;
    return newNode;
}

// Function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create two example linked lists
    ListNode* l1 = createNode(2);
    l1->next = createNode(4);
    l1->next->next = createNode(3);

    ListNode* l2 = createNode(5);
    l2->next = createNode(6);
    l2->next->next = createNode(4);

    // Create an instance of the Solution class
    Solution solution;

    // Call the addTwoNumbers function
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the resulting linked list
    printLinkedList(result);

    // Clean up the memory
    delete l1;
    delete l2;
    delete result;

    return 0;
}
