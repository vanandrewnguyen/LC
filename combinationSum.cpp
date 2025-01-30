class Solution {
public:
    // boilerplate is based of 46. permutations backtracking code
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> list;
        std::vector<int> tmpList;
        doBacktrack(list, tmpList, candidates, target, 0, 0);
        return list;
    }

    void doBacktrack(std::vector<std::vector<int>>& list,
                     std::vector<int>& tmpList,
                     std::vector<int>& candidates,
                     int target,
                     int idx, 
                     int total) {
        
        if (total == target) {
            list.push_back(tmpList);
            return;
        }

        if (total > target || idx >= candidates.size()) {
            // if we surpass the target amount, or have added too many duplicates past the total n numbers given
            // in the first place
            return;
        }

        // add current number again as branch
        tmpList.push_back(candidates[idx]);
        doBacktrack(list, tmpList, candidates, target, idx, total + candidates[idx]);
        tmpList.pop_back();

        // then add next number
        doBacktrack(list, tmpList, candidates, target, idx + 1, total);
    }
};
