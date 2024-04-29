class Solution {
public:
    void fillIsland(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();

        visited[row][col] = 1;
        int dp1[4] = {1, -1, 0, 0};
        int dp2[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int newRow = dp1[i] + row;
            int newCol = dp2[i] + col;

            // if inside bounds, not visited AND available to travel
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && !visited[newRow][newCol] && grid[newRow][newCol] == '1') {
                fillIsland(newRow, newCol, grid, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // We want to run dfs on every island we come across, but at the same time,
        // we keep track of visited. Could also set everything to 0, but ig that 
        // modifies the original 2d array

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    fillIsland(i, j, grid, visited);
                    ans++;
                }
            }
        }

        return ans;
    }
};
