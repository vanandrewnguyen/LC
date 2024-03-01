class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> subs = {{}};
        for (int num : nums) {
            int n = subs.size();
            for (int i = 0; i < n; i++) {
                subs.push_back(subs[i]); // add single number
                subs.back().push_back(num); // add to last seq (1, 2, 3)
            }
        }
        return subs;
    }
};
