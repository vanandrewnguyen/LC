class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;
        
        // loop through strings, pair any differences, swap these then check if string matches
        std::vector<std::pair<char, int>> occ;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                occ.push_back(std::make_pair(s1[i], i));
            }
        }

        if (occ.size() % 2 == 1 || occ.size() > 2) return false;

        // perform swap on s1
        s1[occ[0].second] = occ[1].first;
        s1[occ[1].second] = occ[0].first;
        return (s1 == s2);
    }
};
