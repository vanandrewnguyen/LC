class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        while (true) {
            for (int i = 0; i < n; i++) {
                if (tickets[i] > 0) {
                    tickets[i]--;
                    time++;
                }
                if (i == k && tickets[i] == 0) {
                    return time;
                }
            }
        }
        return 0;
    }
};
