class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                return nums[i];
            }
        }

        return -1;
    }
};
