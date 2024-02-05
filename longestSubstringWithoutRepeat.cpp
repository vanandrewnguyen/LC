class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> set;
        int maxLen = 0;
        int leftInd = 0;
        
        for (int i = 0; i < s.size(); i++) {
            // sliding window
            if (set.count(s[i])) {
                while (set.count(s[i])) {
                    // already exists, abort
                    set.erase(s[leftInd]);
                    leftInd++;
                }
                set.insert(s[i]);
            } else {
                // otherwise put into set
                set.insert(s[i]);
            }

            if (set.size() > maxLen) {
                maxLen = set.size();
            }
        }

        return maxLen;
    }
};
