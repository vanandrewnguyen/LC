class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> list;
        std::vector<int> tmpList;
        doBacktrack(list, tmpList, nums);
        return list;
    }

    void doBacktrack(std::vector<std::vector<int>>& list,
                     std::vector<int>& tmpList,
                     std::vector<int>& nums) {
        if (tmpList.size() == nums.size()) {
            // we have finished building current permutaion of nums list
            list.push_back(tmpList);
        } else {
            // build permutation
            for (int i = 0; i < nums.size(); i++) {
                // if elem alr exists, skip
                if (std::find(tmpList.begin(), tmpList.end(), nums[i]) != tmpList.end()) continue;

                tmpList.push_back(nums[i]);
                doBacktrack(list, tmpList, nums);
                tmpList.pop_back();
            }
        }
    }
};
