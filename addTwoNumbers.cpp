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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) {
                // sum first list
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                // sum second list element
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10; // remainder (we can't translate into numbers then add then retranslate back into list...)
            ListNode* node = new ListNode(sum % 10); // get last entry
            curr->next = node;
            curr = curr->next;
        }

        return dummy->next;
    }
};
