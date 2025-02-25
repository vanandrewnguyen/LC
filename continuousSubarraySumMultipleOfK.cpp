class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixSumMod = 0;
        std::unordered_map<int, int> modSeen; // hash map where key = the prefix sum % k, val = freq, needs 2
        modSeen[0] = -1;

         for (int i = 0; i < nums.size(); i++) {
            // the prefix sum of j%k === i%k
            prefixSumMod = (prefixSumMod + nums[i]) % k;

            if (modSeen.find(prefixSumMod) == modSeen.end()) {
                modSeen[prefixSumMod] = i;
            }
            // ensures that the size of subarray is atleast 2
            if (i - modSeen[prefixSumMod] > 1) {
                return true;
            }
        }

        return false;
    }
};
