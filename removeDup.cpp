class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            s.insert(nums[i]);
        }
        
        int index = 0;
        for (std::set<int>::iterator it = s.begin(); it != s.end(); it++, index++) {
            nums[index] = *it;
        }

        return s.size();
    }
};
