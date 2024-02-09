class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }

    int maxVowels(string s, int k) {
      // Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.  
      int left = 0;
        int right = k-1;
        int maxVowelsInSubset = 0;

        for (int i = left; i <= right; i++) {
            std::cout << s[i] << " is " << isVowel(s[i]) << std::endl;

            if (isVowel(s[i])) {
                maxVowelsInSubset++;
            }
        }

        int currVowelsInSubset = maxVowelsInSubset;
        for (int i = left; i < s.size()-k+1; i++) {
            std::cout << s[left] << " to " << s[right] << " has sum: " << currVowelsInSubset << std::endl;

            currVowelsInSubset -= static_cast<int>(isVowel(s[left]));
            left++;
            right++;
            currVowelsInSubset += static_cast<int>(isVowel(s[right]));

            maxVowelsInSubset = std::max(maxVowelsInSubset, currVowelsInSubset);
        }

        return maxVowelsInSubset;
    }
};
