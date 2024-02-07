class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0, j = m; i < n; i++) {
            // append array... from nums2 appended into nums1
            nums1[j] = nums2[i];
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
};
