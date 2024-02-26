class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }

        for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            std::cout << it->first << " : " << it->second << std::endl;
            if (it->second == 1) {
                return it->first;
            }
        }

        return -1;
    }
};
