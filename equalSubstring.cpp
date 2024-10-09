class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // sliding window, track largest substring that can be covered
        int maxLen = 0;
        int start = 0;
        int sum = 0;

        for (int i = 0; i < s.size(); i++) {
            // as we loop, grab sum (but we remove from trailing end)
            sum += std::abs(t[i] - s[i]);

            while (sum > maxCost) {
                // increment start
                sum -= std::abs(t[start] - s[start]);
                start++;
            }

            // either curr maxlen or length of substring
            maxLen = std::max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};
