class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Find transpose of matrix and reverse rows and columsn
        int len = matrix.size();

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < i; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < len; i++) {
            std::reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
