class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        bubble sort
        traverse from left and compare adjacent elements and the higher one is placed at right side. 
        In this way, the largest element is moved to the rightmost end at first. 
        This process is then continued to find the second largest and place it and so on until the data is sorted.
        */

        int n = nums.size();
        int i, j;
        bool swapped;
        for (i = 0; i < n-1; i++) {
            swapped = false;
            for (j = 0; j < n-1-i; j++) {
                if (nums[j] > nums[j+1]) {
                    // do swap...
                    int tmp = nums[j+1];
                    nums[j+1] = nums[j];
                    nums[j] = tmp;
                    swapped = true;
                }
            }


            if (!swapped) {
                break;
            }
        }
    }
};
