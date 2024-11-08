#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    // Helper function to reverse a linked list starting from the node 'head'
    ListNode* reverse_list(ListNode* head) {
        ListNode* x = NULL;   // Pointer to hold the next node temporarily
        ListNode* y = NULL;   // Pointer to the previous node (initially NULL)
        ListNode* temp = head;// Start at the head of the list

        // Loop to reverse the list
        while (temp != NULL) {
            x = temp->next;   // Store the next node
            temp->next = y;   // Reverse the current node's next pointer to point to the previous node
            y = temp;         // Move y forward (y now points to the current node)
            temp = x;         // Move temp to the next node in the original list
        }

        return y;             // Return the new head of the reversed list (previously the last node)
    }

public:
    // Function to check if the linked list is a palindrome
    bool isPalindrome(ListNode* head) {
        // If the list is empty or has only one node, it's trivially a palindrome
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // If the list has exactly two nodes and they don't match, it's not a palindrome
        if (head->next->next == NULL && head->val != head->next->val) {
            return false;
        }

        // Step 1: Find the middle of the list using the slow and fast pointer technique
        ListNode* slow = head;  // Slow pointer moves one step at a time
        ListNode* fast = head;  // Fast pointer moves two steps at a time

        // Move the slow pointer to the middle and the fast pointer to the end
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;  // Fast pointer moves two steps
            if (fast == NULL) {
                break;                // If fast reaches the end, stop
            }
            slow = slow->next;        // Slow pointer moves one step
        }

        // Step 2: Reverse the second half of the list starting from slow->next
        ListNode* second = reverse_list(slow->next);

        // Disconnect the first half from the second half
        slow->next = NULL;

        // Step 3: Compare the first half and the reversed second half
        ListNode* first = head;   // Start from the head for the first half
        while (second != NULL) {  // Iterate through the reversed second half
            if (second->val != first->val) {
                return false;     // If any values mismatch, the list is not a palindrome
            }
            second = second->next; // Move to the next node in the second half
            first = first->next;   // Move to the next node in the first half
        }

        // If all values match, return true (the list is a palindrome)
        return true;
    }
};
