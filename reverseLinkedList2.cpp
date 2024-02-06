/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // reverse linked list between two indexes... not a swap (dumb example)
        if (!head || !head->next) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // traverse to left index
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        ListNode* curr = prev->next;
        // traverse from left to right
        for (int i = 1; i <= right-left; ++i) {
            // do reverse...
            ListNode* temp = prev->next;
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = temp;
        }

        return dummy->next; // old head
    }
};
