class Solution {
public:
    int search(vector<int>& nums, int target, bool isFirstOccurance) {
        int n = nums.size();
        int start = 0, end = n-1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (isFirstOccurance) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // do binary search to find first occurance of target value
        // then do 2nd binary search to find 2nd occurance
        std::vector<int> pair;
        pair.push_back(search(nums, target, true));
        pair.push_back(search(nums, target, false));
        return pair;
    }
};
