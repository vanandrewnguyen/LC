class Solution {
public:
    string largestNumber(vector<int>& nums) {
        std::vector<std::string> nums_str;
        for (int num : nums) {
            nums_str.push_back(to_string(num));
        }

        // Custom comparator for sorting
        std::sort(nums_str.begin(), nums_str.end(), [](const string &a, const string &b) {
            return (b + a) < (a + b);
        });

        if (nums_str[0] == "0") {
            return "0";
        }

        // Grab largest by concat
        std::string res = "";
        for (const string &num : nums_str) {
            res += num;
        }

        return res;







        // GREEDY algo does not work... sadly.
        // From numbers nums, arrange so that we get the biggest number
        // Get the highest numbers ranked by string sort (e.g. ascii 987_ > 2999)
        // Take the longest number, then pad all other numbers with 0's
        // E.g. [2, 1000, 99] -> [2000, 1000, 9900] -> [9900, 2000, 1000] -> [99, 2, 1000] -> 921000
        
        // int len = nums.size();
        // int max_digit_count = INT_MIN;
        // std::vector<std::pair<std::string, int>> nums_padded;

        // // Get the max digit count, e.g. 1000 = 4
        // for (int i = 0; i < len; i++) {
        //     int digit_count = std::to_string(nums[i]).length();
        //     max_digit_count = std::max(max_digit_count, digit_count);
        // }

        // // Pad every number then sort 
        // for (int i = 0; i < len; i++) {
        //     std::string num_as_string = std::to_string(nums[i]);
        //     int to_pad = max_digit_count - num_as_string.length();
        //     for (int j = 0; j < to_pad; j++) {
        //         num_as_string += "0";
        //     }
        //     nums_padded.push_back(std::make_pair(num_as_string, i));
        // }

        // std::sort(nums_padded.begin(), nums_padded.end(), std::greater<>());
        // std::string res = "";

        // for (int i = 0; i < len; i++) {
        //     std::cout << nums_padded[i].first << std::endl;
        //     res += std::to_string(nums[nums_padded[i].second]);
        // }

        // return res;
    }
};
