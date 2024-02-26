class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // get highest number -> sum, then minus all elems in nums, to get final res
        int n = nums.size();
        int totalSum = (n*(n+1))/2; // sum of arithmetic sequence
        return  totalSum - accumulate(nums.begin(),nums.end(),0);
    }
};
