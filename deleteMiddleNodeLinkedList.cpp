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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }

        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }

        ListNode* prev = nullptr;
        curr = head;
        int count = 0;
        while (curr) {
            if (count == std::ceil(len/2) && prev) {
                prev->next = curr->next;
            }

            count++;
            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};
