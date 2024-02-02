class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) {
            return res;
        }
        if (n == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        
        // left and right as windows
        long l = nums[0];
        long r = nums[0];

        for (int i = 1; i < n; i++) {
            if ((long)nums[i] - nums[i-1] == 1) {
                // array is given as sorted and unique
                r = nums[i];
            } else {
                if (r == l) {
                    // finished seq, with no consecutives on either side
                    res.push_back(to_string(l));
                } else {
                    // finished seq with consec
                    res.push_back(to_string(l) + "->" + to_string(r));
                }

                // start new range
                l = nums[i];
                r = nums[i];
            }
        }

        // last eleme
        if (r == l) {
            res.push_back(to_string(l));
        } else {
            res.push_back(to_string(l) + "->" + to_string(r));
        }

        return res;
    }
};
