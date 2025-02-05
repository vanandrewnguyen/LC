class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        int currIncLen = 1; 
        int currDecLen = 1;
        int maxIncLen = 1;
        int maxDecLen = 1;

        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i] < nums[i+1]) {
                // so we're increasing
                currIncLen++;
                maxIncLen = std::max(maxIncLen, currIncLen);
                currDecLen = 1;
            } else if (nums[i] > nums[i+1]) {
                currDecLen++;
                maxDecLen = std::max(maxDecLen, currDecLen);
                currIncLen = 1;
            } else {
                currDecLen = 1;
                currIncLen = 1;
            }
        }

        return std::max(maxIncLen, maxDecLen);
    }
};
