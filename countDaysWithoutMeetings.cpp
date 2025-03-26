class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // sort + greedy
        // sort, loop to merge nums queries, return unvisited days
        int unvisited = 0;
        int tmp = 1;
        std::sort(meetings.begin(), meetings.end());
        for (std::vector<int>& meeting : meetings) {
            unvisited += std::max(0, meeting[0] - tmp);
            tmp = std::max(tmp, meeting[1]+1); 

            if (tmp > days) { break; }
        }

        return unvisited + std::max(0, days-tmp+1);
    }
};
