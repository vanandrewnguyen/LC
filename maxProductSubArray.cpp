class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = *std::max_element(nums.begin(), nums.end());
        int currMax = 1;
        int currMin = 1;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            currMax = std::max(currMax * nums[i], std::max(currMin * nums[i], nums[i]));
            currMin = std::min(currMax * nums[i], std::min(currMin * nums[i], nums[i]));
            res = std::max(res, currMax);
        }
        return res;

        
        /*
        int len = nums.size();
        int elem = nums[0];
        int prefix = 1;
        int suffix = 1;

        for (int i = 0; i < len; i++) {
            if (prefix == 0) prefix = 1;
            if (suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[len - i - 1]; // prev
            elem = std::max(elem, std::max(prefix, suffix));
        }

        return elem;
        */
    }
};
