class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int x = 0;
        int y = 0;
        // directions
        int dx = 1; // right
        int dy = 0;
        std::vector<int> res;

        // Loop for all cells and move xy based on dxdy
        for (int i = 0; i < rows * cols; i++) {
            res.push_back(matrix[y][x]);
            matrix[y][x] = INT_MIN;
        
            // if not in bounds, or touching a visited spot, turn around
            if (!(x + dx >= 0 && x + dx < cols && y >= 0 + dy && y + dy < rows) || matrix[y+dy][x+dx] == INT_MIN) {
                int temp = dx;
                dx = -dy;
                dy = temp;
            }
            
            x += dx;
            y += dy;
        }

        return res;
    }
};
