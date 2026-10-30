#include <iostream>

/*
 * LEVEL 5 (HARD):
 * 1. Floyd's Tortoise and Hare Cycle Detection & Removal:
 *    - Time: O(N), Space: O(1)
 * 2. In-place Merging of Two Sorted Linked Lists:
 *    - Time: O(N + M), Space: O(1)
 */

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(nullptr) {}
};

// 1. Detect and Break Cycle
bool detectAndRemoveCycle(Node* head) {
    if (!head || !head->next) return false;

    Node* slow = head;
    Node* fast = head;

    // Detect cycle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break; // Cycle detected
    }

    if (slow != fast) return false; // No cycle

    std::cout << "Cycle detected! Finding cycle start node...\n";
    slow = head;
    if (slow == fast) {
        // Special case: loop starts at head
        while (fast->next != slow) fast = fast->next;
    } else {
        while (slow->next != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // Break the loop
    std::cout << "Cycle begins at node: " << fast->next->data << ". Breaking cycle.\n";
    fast->next = nullptr;
    return true;
}

// 2. Merge Two Sorted Lists (In-place)
Node* mergeSortedLists(Node* l1, Node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    Node dummy(0);
    Node* tail = &dummy;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1 ? l1 : l2);
    return dummy.next;
}

void printList(Node* head) {
    while (head) {
        std::cout << head->data << " -> ";
        head = head->next;
    }
    std::cout << "NULL\n";
}

int main() {
    std::cout << "--- 1. Floyd's Cycle Detection & Removal ---\n";
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n4 = new Node(40);
    Node* n5 = new Node(50);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n3; // Creates cycle: 50 -> 30

    detectAndRemoveCycle(n1);
    std::cout << "List after cycle removal: ";
    printList(n1);

    std::cout << "\n--- 2. In-place Merge of Two Sorted Lists ---\n";
    Node* a = new Node(5);
    a->next = new Node(15);
    a->next->next = new Node(25);

    Node* b = new Node(10);
    b->next = new Node(20);
    b->next->next = new Node(30);

    std::cout << "List 1: "; printList(a);
    std::cout << "List 2: "; printList(b);

    Node* merged = mergeSortedLists(a, b);
    std::cout << "Merged: "; printList(merged);

    return 0;
}
