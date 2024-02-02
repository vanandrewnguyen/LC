class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        for (int i = 0; i < prices.size()-1; i++) {
            if (prices[i] < prices[i+1]) {
                int diff = prices[i+1] - prices[i];
                sum += diff;
            }
        }

        return sum;
    }
};
