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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Trivial failure
        if (!head) {
            return NULL;
        }
        
        int size = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;

        // Get size since we delete from back
        while (curr) {
            size++;
            curr = curr->next;
        }

        // Edge fail cases (size is 1, or removing head)
        if (size == 1) { return nullptr; }
        if (n == size) { return head->next; }

        int i = 0; 
        curr = head;
        while (i < size) {
            if (i == size-n) {
                // Delete (pass ptr)
                if (prev) { prev->next = curr->next; }
                break;
            } else {
                // Pass
                prev = curr;
                curr = curr->next;
            }
            i++;
        }

        return head;
    }
};
