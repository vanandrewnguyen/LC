class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int num = citations.size();
        int ans = num;

        for (int i = 0; i < num; i++) {
            if (citations[i] >= ans) {
                break;
            }

            ans--; // this counts down (index should be same if not more than value)
        }

        return ans;
    }
};
