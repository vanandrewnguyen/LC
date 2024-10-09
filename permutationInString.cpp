class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // trivial failures
        if (s1.size() > s2.size()) {
            return false;
        }
        if (s1.size() == s2.size()) { 
            std::string s1Clone = s1;
            std::sort(s1Clone.begin(), s1Clone.end());
            std::string s2Clone = s2;
            std::sort(s2Clone.begin(), s2Clone.end());
            if (s1Clone != s2Clone) {
                return false;
            }
        }
        
        // sliding window for each letter in s2, if matches with s1[0]. slide until full match or else move on
        // but what if we use a freq map, as we slide keep track of increasing freq until we don't...
        std::map<char, int> s1FreqMap;
        std::map<char, int> s2FreqMap;

        // Populate s1 map
        for (int i = 0; i < s1.size(); i++) {
            if (s1FreqMap.find(s1[i]) == s1FreqMap.end()) {
                s1FreqMap[s1[i]] = 0;
            }
            s1FreqMap[s1[i]]++;
        }

        // Sliding window
        int len = s2.size();
        int start = 0;
        int end = s1.size();
        for (int i = 0; i < s1.size(); i++) {
            if (s2FreqMap.find(s2[i]) == s2FreqMap.end()) {
                s2FreqMap[s2[i]] = 0;
            }
            s2FreqMap[s2[i]]++;
            end = i;
        }

        while (end < len) {
            // check if we have match
            if (s1FreqMap == s2FreqMap) {
                return true;
            }

            // remove key if only one occurrence, or just decrement it
            if (s2FreqMap[s2[start]] == 1) {
                s2FreqMap.erase(s2[start]);
            } else {
                s2FreqMap[s2[start]]--;
            }
            start++;
            end++;
            if (s2FreqMap.find(s2[end]) == s2FreqMap.end()) {
                s2FreqMap[s2[end]] = 0;
            }
            s2FreqMap[s2[end]]++;
        }

        return false;
    }
};
