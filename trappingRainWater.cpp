class Solution {
public:
    int trap(vector<int>& height) {
        // get left and right arrays filled up where left and right
        // are max heights encountered from left or right hand side to ith index
        // then, current bar = std::min(left, right) - currHeight
        int n = height.size();
        if (n == 0) {
            return 0;
        }

        std::vector<int> left(n, 0);
        std::vector<int> right(n, 0);

        // fill up left for max prev vs curr
        left[0] = height[0];
        for (int i = 1; i < n; i++) {
            left[i] = std::max(left[i-1], height[i]);
        }

        right[n-1] = height[n-1];
        for (int i = n-2; i >= 0; i--) {
            right[i] = std::max(right[i+1], height[i]);
        }

        // Calculate in one pass
        int res = 0;

        for (int i = 0; i < n; i++) {
            res += std::min(left[i], right[i]) - height[i];
        }

        return res;
    }
};
