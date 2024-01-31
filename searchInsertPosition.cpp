class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), target); 
        if (it != nums.end()) {
            int index = it - nums.begin();
            return index;
        } else {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > target) {
                    return i;
                }
            }
        }

        return nums.size();
    }
};
