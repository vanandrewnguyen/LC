class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        doDfs(n, res, 0, 0, "");

        return res;
    }

    void doDfs(int n, std::vector<std::string>& res, int openParan, int closeParan, std::string s) {
        if (openParan == closeParan && openParan + closeParan == n*2) {
            // we've met n paran (obviously *2 for pairs)
            res.push_back(s);
            return;
        }

        if (openParan < n) {
            doDfs(n, res, openParan+1, closeParan, s + "(");
        }

        if (closeParan < openParan) {
            doDfs(n, res, openParan, closeParan+1, s + ")");
        }
    }
};
