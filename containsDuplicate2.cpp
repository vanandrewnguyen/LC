class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> map;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            // First condition
            if (map.count(nums[i])) {
                // if already encountered, check second condition
                if (abs(i-map[nums[i]]) <= k) {
                    return true;
                }
            }
            map[nums[i]] = i;
        }

        return false;
    }
};
