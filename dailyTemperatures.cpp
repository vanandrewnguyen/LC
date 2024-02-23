class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0);
        std::vector<int> stack; // store indices

        for (int i = temperatures.size() - 1; i >= 0; --i) {
            while (!stack.empty() && temperatures[i] >= temperatures[stack.back()]) {
                stack.pop_back();
            }
            if (!stack.empty()) {
                res[i] = stack.back()-i;
            }
            stack.push_back(i);
        }

        return res;
    }
};
