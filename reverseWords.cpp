class Solution {
public:
    void tokenise(string s, std::vector<string>& words) {
        int n = s.size();
        std::string curr = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (curr.size() != 0) {
                    words.push_back(curr);
                    curr = "";
                }
            } else {
                curr += s[i];
            }
        }

        if (curr.size() != 0) {
            words.push_back(curr);
        }
    }

    string reverseWords(string s) {
        std::vector<std::string> words;
        tokenise(s, words);
        std::reverse(words.begin(), words.end());

        std::string rev = "";
        for (int i = 0; i < words.size(); i++) {
            rev += words[i];
            if (i != words.size()-1) {
                rev += " ";
            }
        }

        return rev;
    }
};
