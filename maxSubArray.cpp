class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return static_cast<double>(nums[0]);
        }

        // find maximum subarray of length k
        int left = 0;
        int right = k;
        double avg = 0.0;

        // initial average
        for (int i = 0; i < k; i++) {
            avg += static_cast<double>(nums[i]) / k;
        }

        double maxAvg = avg;

        // sliding window from 0->k to 1->k+1 to size-k->size
        while (right < nums.size()) {
            avg -= static_cast<double>(nums[left]) / k;
            avg += static_cast<double>(nums[right]) / k;
            maxAvg = std::max(maxAvg, avg);
            left++;
            right++;
        }

        return maxAvg;
    }
};
