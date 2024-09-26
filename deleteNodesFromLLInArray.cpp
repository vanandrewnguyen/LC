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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::set<int> st(nums.begin(), nums.end());
        
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Move ptr to latest value not found 
        while(curr) {
            if (st.count(curr->val)) { 
                curr = curr->next;
            } else {
                break;
            }
        }

        ListNode* new_head = curr;

        // Loop till we hit end
        while (curr && curr->next) {
            if (st.find(curr->next->val) != st.end()) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return new_head;
    }
};
