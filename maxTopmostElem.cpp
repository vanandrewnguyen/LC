class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        // ?? find max of k-1 elem save 1 last step for placing back max elem
        // keep track of max
        int n = nums.size();
        if (n == 1 && k % 2 != 0) { return -1; }
        if (n == 1 && k % 2 == 0) { return nums[0]; }
        if (k == 0) { return nums[0]; }
        if (k == 1) { return nums[1]; }

        int maximum = INT_MIN;
        int i;
        for (i = 0; i < k-1; i++) {
            if (i == n) {
                break;
            }
            maximum = std::max(maximum, nums[i]);
        }
        if (i < n-1) {
            i++;
            // top -> if prematurely ended. Then we return the next to pop off, or maximum
            if (nums[i] > maximum) {
                return nums[i];
            }
        }
        return maximum;
    }
};
