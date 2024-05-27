// 1608

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        
        for (int i = 1; i <= n; i++) {
            // get the lowest index of the dupe number i
            auto it = std::lower_bound(nums.begin(), nums.end(), i);
            // if the end - the lowest bound is equal to the number itself then we've found
            // a number x where there exists x numbers bigger than x in array nums
            if (nums.end() - it == i) {
                return i;
            }
        } 

        return -1;
    }
};
