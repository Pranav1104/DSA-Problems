#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int value) {
        val = value;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;

    // Step 1: Create new nodes and insert them in between the original nodes.
    while (temp != NULL) {
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    // Step 2: Assign random pointers to the new nodes.
    temp = head;
    while (temp != NULL) {
        if (temp->random != NULL)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    // Step 3: Separate the original list and the copied list.
    Node* dummy = new Node(0);
    Node* itr = head;
    Node* newHead = head->next;
    Node* newTemp = dummy;
    
    while (itr != NULL) {
        newTemp->next = itr->next;
        itr->next = itr->next->next;
        itr = itr->next;
        newTemp = newTemp->next;
    }

    return newHead;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->val << ':';
        head->next != NULL ? cout << head->next->val : cout << "NULL";
        head->random != NULL ? cout << "," << head->random->val : cout << ",NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;

    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;

    cout << "Original list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    printList(head);

    cout << "Copy list:(current node:node pointed by next pointer,node pointed by random pointer)\n";
    Node* newHead = copyRandomList(head);
    printList(newHead);

    return 0;
}

