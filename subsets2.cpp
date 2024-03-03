class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> res = {{}};
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int q = res.size();
            for (int j = 0; j < q; j++) {
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }

        // put into set for unique and sort since [1, 4] and [4, 1] are the same
        std::set<std::vector<int>> s;
        for (auto curr : res) {
            // std::sort(curr.begin(), curr.end()); if sort at beginning no need to sort now
            s.insert(curr);
        }
        res.clear();
        for (auto curr : s) {
            res.push_back(curr);
        }

        return res;
    }
};
