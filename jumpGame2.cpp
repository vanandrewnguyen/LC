class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        Input: nums = [2,3,1,1,4]
                      [2,3,3,4,4]
        Output: 2
        */
        
        if (n <= 1) {
            return 0;
        }

        int jumps = 0;
        int n = nums.size();

        // greedy approach
        int maxReach = 0;
        int currReach = 0;
        for (int i = 0; i < n; i++) {
            // maximum reach from curr index
            maxReach = std::max(maxReach, i + nums[i]);

            // if our index is more than what we can reach, then we would've jumped
            if (i >= currReach) {
                jumps++;
                currReach = maxReach;
            }
            if (currReach >= n-1) {
                break;
            }
        }

        return jumps;
    }
};
