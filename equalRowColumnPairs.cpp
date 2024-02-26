class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::map<std::vector<int>, int> m;
        int n = grid.size(); // columns AND rows

        for (int i = 0; i < n; i++) {
            m[grid[i]]++;
        }

        int count = 0;

        for (int i = 0; i < n; i++) {
            std::vector<int> curr;
            for (int j = 0; j < n; j++) {
                //dumb brute force
                curr.push_back(grid[j][i]);
            }
            if (m.find(curr) != m.end()) {
                count += m[curr];
            }
        }

        return count;
    }
};
