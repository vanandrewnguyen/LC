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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currA = headA;
        ListNode* currB = headB;
        ListNode* prevA = nullptr;
        ListNode* prevB = nullptr;
        int lenA = 0, lenB = 0;

        while (currA) {
            lenA++;
            prevA = currA;
            currA = currA->next;
        }

        while (currB) {
            lenB++;
            prevB = currB;
            currB = currB->next;
        }

        // If prevA != prevB, then we don't have an intersection since end nodes aren't the same
        if (prevA != prevB) {
            return nullptr;
        }

        currA = headA;
        currB = headB;

        // match head to equal length
        while (lenA < lenB) {
            lenA++;
            prevB = currB;
            currB = currB->next;
        }
        while (lenB < lenA) {
            lenB++;
            prevA = currA;
            currA = currA->next;
        }
        std::cout << lenA << " : " << lenB << " : " << currA->val << " : " << currB->val << std::endl;

        while (currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }

        return currA;

    }
};
