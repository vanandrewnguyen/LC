class Solution {
public:
    string reverseParentheses(string s) {
        // Every time we see (, push
        // Every time we see ), pop and reverse

        int len = s.size();
        std::string ans = "";
        std::stack<int> st;

        for (int i = 0; i < len; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else if(s[i] == ')') {
                int start = st.top()+1;
                int end = i;

                std::reverse(s.begin()+start, s.begin()+end);
                st.pop();
            }
        }
        
        // Get rid of brackets
        for(auto &ch : s) {
            if(ch != '(' && ch != ')') {
                ans += ch;
            }
        }

        return ans;
    }
};
