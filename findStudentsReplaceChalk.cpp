class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = std::accumulate(chalk.begin(), chalk.end(), 0LL);
        int  remainder = (k % sum);
        int len = chalk.size();
        
        for (int i = 0; i < len; i++) {
            remainder -= chalk[i];
            if (remainder < 0) {
                return i;
            }
        }

        return -1;
    }
};
