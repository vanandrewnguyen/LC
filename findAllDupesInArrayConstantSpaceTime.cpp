class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        std::vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int curr = std::abs(nums[i]);
            if (nums[curr - 1] < 0) {
                res.push_back(curr);
            }
            nums[curr-1] *= -1;
        }
        return res;
    }
};
