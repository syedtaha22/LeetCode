/****************************************************************
 *
 * LeetCode 141: Linked List Cycle
 *
 * *************************************************************/


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next) return false;

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != slow && fast) {
            slow = slow->next;
            fast = fast->next;
            if (!fast) return false;
            fast = fast->next;
        }
        if (!fast || !slow) return false;
        return true;
    }
};
