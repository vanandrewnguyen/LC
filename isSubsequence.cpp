class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sInd = 0;
        int tInd = 0;
        while (sInd < s.size() && tInd < t.size()) {
            if (t[tInd] == s[sInd]) {
                sInd++;
            }
            tInd++;
        }

        return (!(sInd < s.size()));
    }
};
