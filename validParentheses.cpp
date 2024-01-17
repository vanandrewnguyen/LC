class Solution {
public:
    bool isValid(string str) {
        // Fail case
        if (str.length() % 2 != 0) {
            return false;
        }

        std::unordered_map<char, char> map;
        map['}'] = '{';
        map[')'] = '(';
        map[']'] = '[';

        // Loop through and push to stack
        std::stack<char> stack;
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] == '{') || (str[i] == '(') || (str[i] == '[')) {
                stack.push(str[i]);
            } else {
                // Encountering unknown or )}]
                if (stack.size() == 0) return false;
                char latest = stack.top();
                stack.pop();
                if (map[str[i]] != latest) {
                    return false;
                }
            }
        }

        return (stack.size() == 0);
    }
};
