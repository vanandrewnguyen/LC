/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        
        struct ListNode* slowPace = head;
        struct ListNode* fastPace = head;
        
        while (slowPace && fastPace && fastPace->next) {
            slowPace = slowPace->next;
            fastPace = fastPace->next->next;
            if (slowPace == fastPace) {
                return true;
            }
        }
        return false;
    }
};
