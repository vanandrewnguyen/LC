class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // this question wording is bloody stupid
        // He is only grumpy when grumpy[i] == 1

        // double sliding window
        int satisfaction = 0;
        int max_satisfaction = 0;
        int len = customers.size();

        // get the usual satisfaction level without magic powers
        for (int i = 0; i < len; i++) {
            if (grumpy[i] == 0) {
                satisfaction += customers[i];
            }
        }

        // use magic powers for first 'minutes' minutes
        for (int i = 0; i < minutes; i++) {
            satisfaction += customers[i] * grumpy[i];
        }

        max_satisfaction = satisfaction;
        int start = 0;
        int end = minutes-1;

        while (end < len-1) {
            // subtract last index
            satisfaction -= customers[start] * grumpy[start];

            start++;
            end++;

            // add new index
            satisfaction += customers[end] * grumpy[end];

            max_satisfaction = std::max(satisfaction, max_satisfaction);
        }

        return max_satisfaction;
    }
};
