class Solution {
public:
    int maxArea(vector<int>& height) {
        // sliding window, except we move from left most and right most inwards
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        // loop
        while (left < right) {
            // take bounds of rectangle with lower height
            int currArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, currArea);

            // slide
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maxArea;
    }
};
