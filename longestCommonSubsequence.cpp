class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // brute force solution: two pointer starting from text2[0..n] and check longest non-contiguous subsequence
        // in text1[0..m]
        // O(n*m)

        // dp sol
        std::vector<int> dp(text1.size(), 0);
        int longestSubseqLen = 0;
        
        for (char c : text2) {
            int currLen = 0;
            for (int i = 0; i < dp.size(); i++) {
                if (currLen < dp[i]) {
                    // currLen must be the highest subsequence length
                    currLen = dp[i];
                } else if (c == text1[i]) {
                    dp[i] = currLen + 1;
                    longestSubseqLen = std::max(longestSubseqLen, currLen + 1);
                }
            }
        }

        return longestSubseqLen;
    }
};
