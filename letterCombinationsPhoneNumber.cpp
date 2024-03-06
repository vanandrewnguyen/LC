class Solution {
public:
    std::unordered_map<char, std::string> keyboard = {
        { '2', "abc"},
        { '3', "def"},
        { '4', "ghi"},
        { '5', "jkl"},
        { '6', "mno"},
        { '7', "pqrs"},
        { '8', "tuv"},
        { '9', "wxyz"}
    };

    void dfs(std::string& digits, std::string& subset, int index, std::vector<std::string>& res) {        
        if (subset.size() == digits.size()) {
            // finished
            res.push_back(subset);
            return;
        }

        // use index to get index of cell in digits
        std::string& str = keyboard[digits[index]];
        for (int i = 0; i < str.size(); i++) {
            subset.push_back(str[i]);
            dfs(digits, subset, index+1, res);
            subset.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return {};
        }

        std::vector<std::string> res;
        std::string subset = "";
        dfs(digits, subset, 0, res);    

        return res;
    }
};
