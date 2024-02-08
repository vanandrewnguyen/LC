class Solution {
public:
    string removeStars(string s) {
        std::stack<char> stack;

        for (int i = 0; i < s.size(); i++) {
            stack.push(s[i]);

            if (s[i] == '*') {
                stack.pop();
                stack.pop();
            }
        }

        std::string res = "";
        while (stack.size()) {
            res += stack.top();
            stack.pop();
        }
        std::reverse(res.begin(), res.end());

        return res;
    }
};
