class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // same char set
        // same occurance if swap, freq of alphabets of both strings are permutations
        std::array<int, 26> c1 = {};
        std::array<int, 26> c2 = {};

        for (int i = 0; i < word1.size(); i++) {
            c1[word1[i] - 'a']++;
        }

        for (int i = 0; i < word2.size(); i++) {
            c2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            bool cInWord1 = c1[i] > 0;
            bool cInWord2 = c2[i] > 0;

            if ((cInWord1 && !cInWord2) || (!cInWord1 && cInWord2)) {
                return false;
            }
        }

        std::sort(c1.begin(), c1.end());
        std::sort(c2.begin(), c2.end());

        for (int i = 0; i < 26; i++) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }

        return true;
    }
};
