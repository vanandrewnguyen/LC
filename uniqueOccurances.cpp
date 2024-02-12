class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int, int> m;
        std::set<int> s;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]]++;
        }

        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            if (!s.insert(it->second).second) {
                return false;
            }
        }

        return true;
    }
};
