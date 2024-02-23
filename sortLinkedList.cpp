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
    ListNode* findMid(ListNode* head) {
        // 2 ptr trick
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        if (!left || !right) {
            return (left) ? left : right;
        }

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;
        // iterate to sort
        while (left && right) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left || right) {
            // last node
            curr->next = (left) ? left : right;
        }
        return ans->next;
    }

    ListNode* sortList(ListNode* head) {
        // merge sort 
        // two pointers, slow and fast, fast pointer will reach the end while slow pointer
        // reaches the middle, then recurse to continually split up lists
        if (!head || !head->next) {
            return head;
        }

        ListNode* newHead = head;
        ListNode* mid = findMid(head);
        newHead = mid->next;
        mid->next = nullptr;  // disjoint lists
        ListNode* left = sortList(head);
        ListNode* right = sortList(newHead);

        return mergeList(left, right);
    }
};
