class Solution {
public:
    bool canJump(vector<int>& nums) {
        // trivial case
        int n = nums.size();
        if (n == 1) {
            return (nums[0] >= 0);
        }

        int remainingJumps = 0;
        for (int i = 0; i < n; i++) {
            if (remainingJumps < 0) {
                return false;
            } else if (nums[i] > remainingJumps) {
                remainingJumps = nums[i];
            }

            remainingJumps--;
        }

        return true;
    }
};
