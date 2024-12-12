class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Restrictions: cannot use more than O(1) space, so simple method could be to 
        // keep a set of pairs (coords with each 0 found)
        // Using hint: use first row and column as record, if find 0, update same row/col with 0

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Track if first col/row has zero, since we are using this to denote whether to convert row/col into 0's
        bool firstRowZero = false;
        bool firstColZero = false;

        for (int i = 0; i < rows; i++) {
            if (matrix[i][0] == 0) {
                firstRowZero = true;
                break;
            }
        }
        for (int i = 0; i < cols; i++) {
            if (matrix[0][i] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Set flags as 0
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Set the marked row / col to 0
        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < cols; c++) {
                    matrix[r][c] = 0;
                }
            }
        }
        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < rows; r++) {
                    matrix[r][c] = 0;
                }
            }
        }


        // Set first row.col according to flags
        if (firstColZero) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }
        if (firstRowZero) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }  
    }
};
