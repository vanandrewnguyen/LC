class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> set1;
        std::unordered_set<int> set2;
        std::vector<vector<int>> res;

        // populate sets
        for (std::vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
            set1.insert(*it);
        }
        for (std::vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
            set2.insert(*it);
        }

        // check difference
        std::vector<int> distinct1, distinct2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct2.push_back(num);
            }
        }

        return {distinct1, distinct2};
    }
};
