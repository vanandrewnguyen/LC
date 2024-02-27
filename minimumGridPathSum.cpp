class Solution {
public:
    int doSum(std::vector<std::vector<int>>& minPath, std::vector<std::vector<int>> &grid, int row, int col) {
        if(row == 0 && col == 0) {
            return grid[0][0];
        }
        if(row < 0 || col < 0) {
            // failed... out of bounds
            return INT_MAX;
        }
        if(minPath[row][col] != 0) {
            // path has alr been found
            return minPath[row][col];
        }

        minPath[row][col] = grid[row][col] + min(doSum(minPath, grid, row - 1, col), doSum(minPath, grid, row, col - 1));
        return minPath[row][col];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int ans = 0;
        int cols = grid.size();
        int rows = grid[0].size();
        
        std::vector<std::vector<int>> minPath(cols+1, std::vector<int>(rows+1, 0));
        return doSum(minPath, grid, cols-1, rows-1);
    }
};
