class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp array init all elem at 1, this array stores the length of longest increasing subsequence
        // ending at each index i from 0..n-1
        // loop array, at each elem 1..n-1 compare all elem before 0..i-1, if prev elem smaller, then can be in subseq
        // so we add their longest subseq length
        int n = nums.size();
        std::vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // add to dp sum for index i
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            std::cout << dp[i] << " ";
        }

        return *std::max_element(dp.begin(), dp.end());

    }
};
