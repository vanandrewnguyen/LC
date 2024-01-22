class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        std::vector<int> v(len);

        for (int i = 0; i < len; i++) {
            v[(i+k)%len] = nums[i];
        }

        nums = v;
    }
};
