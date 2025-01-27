class Solution {
public:
    int search(vector<int>& nums, int target) {
        // sorting means nlogn time, too long
        // binary search needs an ascending array logn
        // single loop means n time, too long... - use single loop to find where the index shift is
        // we could use binary search but we need to find the index shift - n + log n time...

        // binary search simultaneously to find pivot and res
        // [4,5,6,7,0,1,2]


        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[low] <= nums[mid]) {
                // this means the left to mid is ascending
                if (nums[low] <= target && target < nums[mid]) {
                    // this means target must be to the left, no turning point
                    high = mid - 1;
                } else {
                    // target is higher than lowest point, turning point to the right
                    low = mid + 1;
                }
            } else {
                // some turning point exists between low and high
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

        }

        return -1;
    }
};
