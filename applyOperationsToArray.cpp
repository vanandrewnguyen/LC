class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int writeIndex = 0; 
        // writeInd -> nonzero elem

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && nums[i] == nums[i+1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }

            // Shift to nonzero elem index
            if (nums[i] != 0) {
                if (i != writeIndex) {
                    std::swap(nums[i], nums[writeIndex]);
                }
                writeIndex++;
            }
        }

        return nums;
    }
};

/*
official brute force

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> modifiedNums;

        // Step 1: Apply operations on the array
        for (int index = 0; index < n - 1; index++) {
            if (nums[index] == nums[index + 1] && nums[index] != 0) {
                nums[index] *= 2;
                nums[index + 1] = 0;
            }
        }

        // Step 2: Move non-zero elements to the front
        for (int num : nums) {
            if (num != 0) {
                modifiedNums.push_back(num);
            }
        }

        // Step 3: Append zeros to maintain the original size
        while (modifiedNums.size() < n) {
            modifiedNums.push_back(0);
        }

        return modifiedNums;
    }
};
*/
