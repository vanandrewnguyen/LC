class Solution {
public:
    string frequencySort(string s) {
        std::unordered_map<char, int> m;
        std::multimap<int,char> mm; // cool new ds multimap! can have multiple identical keys
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }

        for (std::unordered_map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
            // freq : value pair
            mm.insert({it->second, it->first});
        }

        std::string res = "";
        for (std::multimap<int,char>::reverse_iterator it = mm.rbegin(); it != mm.rend(); ++it) {
            std::cout << it->first << ": " << it->second << std::endl;
            for (int i = 0; i < it->first; i++) {
                res += it->second;
            } 
        }
    
        return res;
    }
};
