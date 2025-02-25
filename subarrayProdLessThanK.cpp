class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int count = 0;
        int product = 1;

        // sliding window
        for (int left = 0, right = 0; right < nums.size(); right++) {
            product *= nums[right]; // slide rhs
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};
