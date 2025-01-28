class Solution {
public:
    void catchFishInPond(std::vector<std::vector<int>>& grid, 
                        std::vector<std::vector<int>>& visited,
                        int x, int y, int& sum) {  
        sum += grid[x][y];
        visited[x][y] = 1;
        
        if (x-1 >= 0 && visited[x-1][y] == 0 && grid[x-1][y] > 0) {
            catchFishInPond(grid, visited, x-1, y, sum);
        }
        if (y-1 >= 0 && visited[x][y-1] == 0 && grid[x][y-1] > 0) {
            catchFishInPond(grid, visited, x, y-1, sum);
        }
        if (x+1 <= grid.size()-1 && visited[x+1][y] == 0 && grid[x+1][y] > 0) {
            catchFishInPond(grid, visited, x+1, y, sum);
        }
        if (y+1 <= grid[0].size()-1 && visited[x][y+1] == 0 && grid[x][y+1] > 0) {
            catchFishInPond(grid, visited, x, y+1, sum);
        }
    }
    
    int findMaxFish(std::vector<std::vector<int>>& grid) {
        int height = grid[0].size();
        int width = grid.size();
        std::vector<std::vector<int>> visited(width, std::vector<int>(height, 0));
        int highestSum = 0;

        for (int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {
                if (visited[x][y] == 0 && grid[x][y] > 0) {
                    int currSum = 0; 
                    catchFishInPond(grid, visited, x, y, currSum);
                    highestSum = std::max(highestSum, currSum);
                }
            }
        }   

        return highestSum;
    }
};
