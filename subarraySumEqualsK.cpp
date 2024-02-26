class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        std::map<int, int> m;
        int curr = 0;
        int count = 0;

        m[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];
            if (m.find(curr - k) != m.end()) {
                // found complement sum
                count += m[curr - k];
            }
            m[curr] += 1;
        }
        return count;
    }
};
