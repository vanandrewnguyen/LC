class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            if (nums[right] == 0) {
                // if we get a 0 on the right, we decrease the number of flippable elem (k)
                k--;
            }
            if (k < 0) {
                // if k < 0 then we move left forward until k is 0+
                if (nums[left] == 0) {
                    k++;
                }
                left++;
            }
            right++;
        }

        return right - left;
    }
};
