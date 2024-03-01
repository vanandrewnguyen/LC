class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        Given an integer array nums, return all the triplets
        [nums[i], nums[j], nums[k]] such that i != j, i != k,
        and j != k, and nums[i] + nums[j] + nums[k] == 0.
        */
        std::sort(nums.begin(), nums.end());

        // unique triplets, vector for res
        std::set<std::vector<int>> s;
        std::vector<std::vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if (currSum == 0) {
                    // insert and reduce range towards middle
                    s.insert({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                } else if (currSum < 0) {
                    // too msmall, move lower end
                    j++;
                } else {
                    k--;
                }
            }
        }

        for (std::set<std::vector<int>>::iterator it = s.begin(); it != s.end(); it++) {
            res.push_back(*it);
        }

        return res;
    }
};
