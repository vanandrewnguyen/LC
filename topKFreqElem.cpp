class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // dump map values into vector of pairs to sort by second value
        std::vector<std::pair<int, int>> dump; // where first value should be freq, second is num
        for (std::unordered_map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
            dump.push_back(std::make_pair(it->second, it->first));
        }

        std::sort(dump.begin(), dump.end());

        // copy into new vector....
        n = dump.size();
        std::vector<int> res;
        for (int i = n-k; i < n; i++) {
            res.push_back(dump[i].second);
        }

        return res;
    }
};
