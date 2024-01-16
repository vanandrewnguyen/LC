class Solution {
public:
    int romanToInt(string s) {
        // Use dictionary to order roman numerals
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int integer = 0;

        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] < m[s[i+1]]) {
                // Case 1: we have a smaller subtracting number e.g. IX = 9, -1 +10 = 9
                integer -= m[s[i]];
            } else {
                // Case 2: additive number
                integer += m[s[i]];
            }
        }

        return integer;
    }
};
