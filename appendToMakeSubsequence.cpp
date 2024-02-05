class Solution {
public:
    int appendCharacters(string s, string t) {
        // identical to is subsequence... but check against s instead of t but return diff
        int sInd = 0;
        int tInd = 0;
        while ((sInd < s.size()) && (tInd < t.size())) {
            if (s[sInd] == t[tInd]) {
                tInd++;
            }
            sInd++;
        }

        std::cout << sInd << s[sInd] << std::endl;
        std::cout << tInd << t[tInd] << std::endl;

        return (t.size() - tInd);
    }
};
