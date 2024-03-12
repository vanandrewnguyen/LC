class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        std::vector<std::vector<int>> uniqueSet, res;
        std::vector<int> curr;

        // get all subsequences and remove those that are duplicates
        // and those that aren't increasing (insert in new vecVec<int>)
        getAllSubsequence(0, nums, uniqueSet, curr);
        std::sort(uniqueSet.begin(), uniqueSet.end());
        // iterator first and last... unique till end
        uniqueSet.erase(std::unique(uniqueSet.begin(), uniqueSet.end()), uniqueSet.end());
        int flag = 0;
        for (int i = 0; i < uniqueSet.size(); i++) {
            for (int j = 1; j < uniqueSet[i].size(); j++) {
                if (uniqueSet[i][j] < uniqueSet[i][j-1]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                res.push_back(uniqueSet[i]);
            }
            flag = 0;
        }

        return res;
    }

    void getAllSubsequence(int i, std::vector<int>& nums, std::vector<std::vector<int>> &res, std::vector<int>& curr) {
        // surpassed max len
        if (i >= nums.size()) {
            // just taking last case
            if (curr.size() >= 2) {
                res.push_back(curr);
            }
            return;
        }

        curr.push_back(nums[i]);
        getAllSubsequence(i+1, nums, res, curr);
        curr.pop_back();
        getAllSubsequence(i+1, nums, res, curr);
    }
};
