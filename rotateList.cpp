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

// like a circular array, but a linked list
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return 0;
        }

        // get length
        int len = 0;
        ListNode* newHead = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        k = k % len;

        // trivial cases
        if (k == 0 || !head->next) {
            return head;
        }

        // now go to index
        int i = 0;
        curr = head;
        while (curr) {
            i++;
            // when index is reached, cut off previous connection, form new head
            if (i == (len-k+1)) {
                prev->next = nullptr;
                newHead = curr;
            }
            prev = curr;
            curr = curr->next;
        }

        // tie off end of list to old head
        prev->next = head;

        return newHead;
    }
};
