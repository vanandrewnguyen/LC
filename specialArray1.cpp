class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return true;

        for (int i = 1; i < len; i++) {
            bool currEven = (nums[i] % 2 == 0);
            bool prevEven = (nums[i-1] % 2 == 0);

            if ((currEven && prevEven) || (!currEven && !prevEven)) return false;
        }

        return true;
    }
};
