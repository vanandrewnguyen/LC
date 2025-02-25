class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // brute force is O(n^2) double loop and check for j = i..n if sum % 2 == 0

        /*
If prefixSum is even, it means the subarray sum from the start to the current index is even. To form an odd subarray, we need to subtract a previously seen odd prefix sum. So, we add the count of previously seen odd prefix sums to our answer.

If prefixSum is odd, the subarray sum from the start to the current index is odd. To form another odd subarray, we need to subtract a previously seen even prefix sum. So, we add the count of previously seen even prefix sums to our answer.
o m g
        */

        int count = 0;
        int n = arr.size();
        std::vector<int> prefixSum(n, 0);
        
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];
        }

        int evenSums = 1;
        int oddSums = 0;
        const int MOD = 1e9 + 7;
        
        for (int i = 0; i < n; i++) {
            if (prefixSum[i] % 2 == 0) {
                count += oddSums;
                evenSums++;
            } else {
                count += evenSums;
                oddSums++;
            }

            count = count % MOD;
        }

        return count;
    }
};
