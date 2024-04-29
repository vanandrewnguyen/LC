class Solution {
public:
    bool isIsomorphic(string s, string t) {
        std::map<char, char> compareMap;
        for (int i = 0; i < s.size(); i++) {
            if (compareMap.find(s[i]) == compareMap.end()) {
                // Does pair exist? Does it match?
                for (auto it : compareMap) {
                    if (it.second == t[i]) {
                        if (it.first != s[i]) {
                            return false;
                        }
                    }
                }
                // Otherwise just create pair
                compareMap[s[i]] = t[i];
            } else {
                // Is in map
                if (t[i] != compareMap[s[i]]) {
                    return false;
                }
            }
        }

        return true;
    }
};
