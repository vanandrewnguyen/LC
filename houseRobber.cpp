// see heroes3001 comment...
/*
A robber has 2 options: a) rob current house i; b) don't rob current house.
If an option "a" is selected it means she can't rob previous i-1 house but can safely proceed to the one before previous i-2 and gets all cumulative loot that follows.
If an option "b" is selected the robber gets all the possible loot from robbery of i-1 and all the following buildings.
So it boils down to calculating what is more profitable:

robbery of current house + loot from houses before the previous
loot from the previous house robbery and any loot captured before that
rob(i) = Math.max( rob(i - 2) + currentHouseValue, rob(i - 1) )
*/

class Solution {
public:
    int doRob(std::vector<int>& nums, std::vector<int>& houses, int i) {
        if (i < 0) {
            return 0;
        }
        if (houses[i] >= 0) {
            return houses[i];
        }
        int res = std::max(doRob(nums, houses, i-2) + nums[i], doRob(nums, houses, i-1));
        houses[i] = res;
        return res;
    }

    int rob(vector<int>& nums) {
        std::vector<int> houses(nums.size()+1, -1);
        return doRob(nums, houses, nums.size()-1);
    }
};

// too slow
// class Solution {
// public:
//     int doRob(vector<int>& nums, int i) {
//         if (i < 0) {
//             return 0;
//         }
//         return std::max(doRob(nums, i-2) + nums[i], doRob(nums, i-1));
//     }

//     int rob(vector<int>& nums) {
//         return doRob(nums, nums.size()-1);
//     }
// };
