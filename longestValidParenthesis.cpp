class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        int maxLen = 0;
        std::stack<int> stack;

        stack.push(-1);

        for (int i = 0; i < len; i++) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.empty()) {
                    stack.push(i);
                } else {
                    maxLen = std::max(maxLen, i - stack.top());
                }
            }
        }


        return maxLen;
    }
};
