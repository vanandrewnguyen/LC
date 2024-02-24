class Solution {
public:
    vector<int> partitionLabels(string s) {
        // given a string, divide into partitions where characters in each partition
        // do not appear in any other partition

        // create hashmap [key: char -> value: int] where value = LAST occurance of char
        std::unordered_map<char,int> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]] = i;
        }

        std::vector<int> res;
        int prev = -1;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            // greedy interval merge
            maxi = std::max(maxi, map[s[i]]); // original gap or latest occurance
            if (maxi == i) {
                // split partition
                // since we know this index matches the last occurance of the curr char
                res.push_back(maxi-prev);
                prev = maxi;
            }
        }
        return res;
    }
};
