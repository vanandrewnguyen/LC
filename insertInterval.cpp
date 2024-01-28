class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::vector<vector<int>> ans;
        int n = intervals.size();

        // sort then merge
        std::sort(intervals.begin(), intervals.end());

        int i = 0;
        int prev0 = intervals[0][0];
        int prev1 = intervals[0][1];

        while (i < n) {
            if (intervals[i][0] >= prev0 && intervals[i][0] <= prev1) {
                // Set up and increase interval range
                prev1 = std::max(prev1, intervals[i][1]);
                i++;
            } else {
                // Bigger range, so merge 
                std::vector<int> newInterval;
                newInterval.push_back(prev0);
                newInterval.push_back(prev1);
                ans.push_back(newInterval);
                prev0 = intervals[i][0];
                prev1 = intervals[i][1];
                i++;
            }
        }

        // add last interval
        std::vector<int> newInterval;
        newInterval.push_back(prev0);
        newInterval.push_back(prev1);
        ans.push_back(newInterval);
        return ans;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
};
