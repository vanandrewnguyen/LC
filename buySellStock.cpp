class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int sellProfit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            int currDiff = prices[i] - minPrice;
            if (currDiff > sellProfit) {
                sellProfit = currDiff;
            }
        }

        return sellProfit;
    }
};
