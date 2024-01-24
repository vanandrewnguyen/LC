class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> s;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            s.insert(*it);
        }

        int ans = 0;
        for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            // is previous elem in set? if so, start chain
            if (!s.count(*it - 1)) {
                int curr = *it;
                int count = 1;

                // chain from curr elem
                while (s.count(curr + 1)) {
                    curr++;
                    count++;
                }
                ans = std::max(ans, count);
            }
        }
        return ans;
    }
};
