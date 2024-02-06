class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::stringstream ss(s);

        std::vector<string> list;
        std::string word;

        while (ss >> word) {
            list.push_back(word);
        }

        // trivial fail case
        if (list.size() != pattern.size()) {
            return false;
        }

        std::unordered_map<char, string> map;
        for (int i = 0; i < pattern.size(); i++) {
            std::unordered_map<char, string>::iterator it = map.find(pattern[i]);
            if (it == map.end()) {
                // doesn't exist, so put a->dog, char to word
                map[pattern[i]] = list[i];
            } else if (it->second != list[i]) {
                return false;
            }
        }
        
        // now we need to know if there are dupes
        // e.g. abba -> dog dog dog dog 
        // both a AND b are dupes with dog
        std::unordered_set<string> set;
        for (std::unordered_map<char, string>::iterator it = map.begin(); it != map.end(); it++) {
            if (!set.insert(it->second).second) {
                return false;
            }
        }

        return true;
    }
};
