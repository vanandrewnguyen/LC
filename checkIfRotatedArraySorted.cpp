// number 1752
class Solution {
public:
    bool check(vector<int>& nums) {
        // take nums, give 3 cases for sorted, 1 unsorted
        // [1, 2, 3, 4] all ascending and original
        // [4, 1, 2, 3] has been rotated
        // [2, 3, 4, 1] rotation puts first elem at the back
        // [1, 3, 2, 4]

        int len = nums.size();
        int startIndex = 0;

        for (int i = 1; i < len; i++) {
            if (nums[i] < nums[i-1]) {
                startIndex = i;
            }
        }

        for (int i = 1; i < len; i++) {
            int currIndex = (startIndex + i) % len;
            int prevIndex = (currIndex != 0) ? currIndex-1 : len-1;
            if (nums[currIndex] < nums[prevIndex]) {
                return false;
            }
        }
        
        return true;
    }
};
