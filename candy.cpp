class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        int maxRating = 2 * 10000 + 1;
        std::vector<int> candy(size, 1);
        int minCandy = 0;
        /*
        This problem is actually quite easy once you figure out the algorithm:
        Traverse the children from left to right. Any child that has a higher rating than their LH neighbour gets 1 more candy than their LH neighbour. Otherwise they get 1 candy.
        Next, traverse the children from right to left. Any child that has a higher rating than their RH neighbour gets 1 more candy than their RH neighbour - unless they already have more candies than their RH neighbour in which case the number of candies is unchanged.
        Finally, add up all the candies and return the total to the caller.
        */
        for (int i = 0; i < size; i++) {
            int left = (i-1) > -1 ? ratings[i-1] : maxRating;
            int self = ratings[i];
            if (self > left) {
                candy[i] = candy[i-1] + 1;
            }
        }
        for (int i = size-1; i > -1; i--) {
            int right = (i+1) < size ? ratings[i+1] : maxRating;
            int self = ratings[i];
            if (self > right) {
                if (candy[i] <= candy[i+1]) {
                    candy[i] = candy[i+1] + 1;
                }
            }
        }
        minCandy = std::accumulate(candy.begin(), candy.end(), 0);
        return minCandy;

    }
};
