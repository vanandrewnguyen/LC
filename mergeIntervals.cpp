class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(),intervals.end());

        std::vector<std::vector<int>> res;
        int n = intervals.size();
        res.push_back(intervals[0]);

        for (int i = 1; i < n; i++) {
            std::vector<int> latest = res.back();
            if (latest[1] >= intervals[i][0]) {
                if (latest[1] > intervals[i][1]) {
                    // keep larger range, e.g. [1, 10] -> [3, 4]
                    res.pop_back();
                    std::vector<int> newMerge = {latest[0], latest[1]};
                    res.push_back(newMerge);
                } else {
                    // replace, e.g. [1, 4] -> [2, 6]
                    res.pop_back();
                    std::vector<int> newMerge = {latest[0], intervals[i][1]};
                    res.push_back(newMerge);
                }
            } else {
                // disjoint
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
