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
    bool isPalindrome(ListNode* head) {
        std::vector<int> list;
        ListNode* curr = head;
        while (curr) {
            list.push_back(curr->val);
            curr = curr->next;
        }

        // valid palindrome for list
        int start = 0;
        int end = list.size() - 1;
        while (start <= end) {
            if (tolower(list[start]) != tolower(list[end])) {
                return false;
            } else {
               start++;
               end--;
           }
       }
       return true;
    }
};
