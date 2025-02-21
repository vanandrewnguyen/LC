class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> palinParts;
        vector<string> parts;
        doPartition(s, 0, parts, palinParts);
        return palinParts;
    }

    void doPartition(string& str, int start, vector<string>& parts, vector<vector<string>>& palinParts) {
        int len = str.size();
        if (start == len) {
            // hit the end of substring
            palinParts.push_back(parts);
        } else {
            for (int i = start; i < len; i++) {
                // from startIndex..n for startIndex = 1..n-1
                if (isPalindrome(str, start, i)) {
                    parts.push_back(str.substr(start, i - start + 1));
                    doPartition(str, i+1, parts, palinParts);
                    parts.pop_back();
                }
            }
        }
    }

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};
