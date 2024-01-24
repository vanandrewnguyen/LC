class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::map<int, int> m;

        // Use freq hash map
        for (int i = 0; i < nums.size(); i++) {
            if (!m.count(nums[i])) {
                m.insert(std::pair<int, int>(nums[i], 1));
            } else {
                m[nums[i]] = m[nums[i]] + 1;
            }
        }

        int index = 0;
        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++, index++) {
            // could simplify?
            if (it->second >= 2) {
                nums[index] = it->first;
                index++;
                nums[index] = it->first;
            } else if (it->second == 1) {
                nums[index] = it->first;
            }
        }

        return index;
    }
};
