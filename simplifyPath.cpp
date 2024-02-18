class Solution {
public:
    string simplifyPath(string path) {
        // create stack ... loop across string
        // / = ignore, append dir names
        // if tmp = ., ignore, if = .., pop layer
        // accumulate all temp paths
        std::stack<std::string> s;
        std::string res;

        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                continue;
            }

            std::string temp;
            while (i < path.size() && path[i] != '/') {
                temp += path[i];
                ++i;
            }
            if (temp == ".") {
                continue;
            } else if (temp == "..") {
                if (!s.empty()) {
                    s.pop();
                }
            } else {
                s.push(temp);
            }
        }

        // accumulate
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }

        // base
        if (res.size() == 0) {
            res = "/";
        }

        return res;
    }
};
