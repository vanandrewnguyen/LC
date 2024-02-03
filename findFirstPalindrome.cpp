class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            // check curr is palindrome
            int start = 0;
            int end = words[i].size() - 1;
            bool isP = true;
            while (start <= end) {
                if (words[i][start] != words[i][end]) {
                    isP = false;
                    break;
                } else {
                    start++;
                    end--;
                }
            }
            if (isP) { return words[i]; }
        }

        return "";
    }
};
