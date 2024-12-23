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
    ListNode* partition(ListNode* head, int x) {
        ListNode part1(0), part2(0);
        ListNode* beforeCurr = &part1;
        ListNode* afterCurr = &part2;

        while (head) {
            if (head->val < x) {
                beforeCurr->next = head;
                beforeCurr = head;
            } else {
                afterCurr->next = head;
                afterCurr = head;
            }
            head = head->next;
        }

        afterCurr->next = nullptr;
        beforeCurr->next = part2.next;

        return part1.next;
    }
};
