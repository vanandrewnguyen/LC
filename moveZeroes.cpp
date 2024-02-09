class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();
        while(i < n && j < n) {
            if (nums[i] != 0) { i++; }
            if (nums[j] == 0) { j++; }

            if ((i < n and j < n) && (i < j)) {
                std::swap(nums[i],nums[j]);
            }
            
            j++;
        }
    }
};
