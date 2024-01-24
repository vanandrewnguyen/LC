class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0, ans = INT_MAX;
        long long sum = 0;

        // Sliding window
        while (end < nums.size()) {
            sum += nums[end];
            if (sum >= target) {
                // Backtrack from start to reduce sum
                while (sum >= target) {
                    sum -= nums[start];
                    start++;
                }

                start--;
                sum += nums[start];
                ans = std::min(ans, end - start + 1);
            }

            end++;
        }

        return (ans == INT_MAX) ? 0 : ans;
    }
};
