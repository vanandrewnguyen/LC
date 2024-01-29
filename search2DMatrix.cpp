class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // std::find??? is that cheating
        for (std::vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); it++) {
            std::vector<int> sublist = *it;
            if (std::find(sublist.begin(), sublist.end(), target) != sublist.end()) {
                return true;
            }
        }

        return false;
    }
};
