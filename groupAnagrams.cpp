class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<string>> m;
        int n = strs.size();

        // sort the word, e.g. eat becomes aet, then store it in map to append new words to
        for (int i = 0; i < n; i++) {
            std::string copy = strs[i];
            std::sort(copy.begin(), copy.end());
            if (m.count(copy)) {
                m[copy].push_back(strs[i]);
            } else {
                std::vector<string> newVec;
                newVec.push_back(strs[i]);
                m.insert(std::make_pair(copy, newVec));
            }
        }

        // then build the final result
        std::vector<std::vector<string>> res;
        for (std::unordered_map<std::string, std::vector<string>>::iterator it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
