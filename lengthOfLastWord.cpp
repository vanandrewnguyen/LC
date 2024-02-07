class Solution {
public:
    int lengthOfLastWord(string s) {
        // split into array
        std::stringstream ss(s);

        std::vector<string> list;
        std::string word;

        while (ss >> word) {
            list.push_back(word);
        }

        return (list[list.size()-1]).size();
    }
};
