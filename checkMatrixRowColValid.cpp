class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int len = matrix.size();
        std::unordered_set<char> rows[len];
        std::unordered_set<char> cols[len]; 
        
        for (int r = 0; r < len; ++r) {
            for (int c = 0; c < len; ++c) {
                if (!rows[r].insert(matrix[r][c]).second) {
                    return false;
                }
                if (!cols[c].insert(matrix[r][c]).second) {
                    return false;
                }
            }
        }

        return true;
    }
};
