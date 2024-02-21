class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // obviously rotten oranges can be an entry point for bfs
        // each orange = node, edge = adjacent or not.
        // 1. loop through 2d array to find rotten oranges and note position
        // 2. each position is in a queue, while fresh oranges exists, run bfs. 
        // 3. bfx on each rotten orange
        // 4. reachable? or unreachable.

        int rows = grid.size();
        int cols = grid[0].size();
        std::queue<std::pair<int, int>> q;
        std::vector<std::vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        int fresh = 0;
        
        // find rotten
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});  
                } else if (grid[i][j] == 1) {
                    fresh++;  
                }
            }
        }

        // start
        int result = -1;
        q.push({-1, -1}); // this is meant to mark each minute

        // run bfs
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == -1) {
                // first iteration
                result++; // first minute
                if (!q.empty()) { // if we have neighbours to infect, add another minute
                    q.push({-1, -1});
                }
            } else {
                // run bfs, add neighbours
                for (int i = 0; i < dirs.size(); i++) {
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];
                    
                    // Check position in bounds
                    if (x < 0 || x >= rows || y < 0 || y >= cols) {
                        continue;
                    }
                    
                    if (grid[x][y] == 1) {
                        // Contaminate the fresh orange
                        grid[x][y] = 2;
                        fresh--;  // Decrement the count of fresh oranges
                        // This orange will now contaminate others, so add to the queue
                        q.push({x, y});
                    }
                }
            }
        }

        return (fresh == 0) ? result : -1;
    }
};
