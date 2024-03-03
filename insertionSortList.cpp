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
    ListNode* insertionSortList(ListNode* head) {
        // the quick dumb way is to make an array from head ll, then sort, then edit in place
        // but alas we cannot :((

        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        std::vector<int> arr;
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        // do insertion sort (without function call std::sort)
        for (int j = 1; j < arr.size(); j++) {
            int curr = arr[j]; // start off with 2nd elem till end
            int i = j - 1; // prev,  loop back
            while (i > -1 && arr[i] > curr) {
                arr[i+1] = arr[i];
                i--;
            }
            arr[i+1] = curr;
        }

        // construct ll... consumes space
        temp = dummy;
        for (int i = 0; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummy->next;

    }
};
