class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> s = {};
        int len = asteroids.size();

        for (int i = 0; i < asteroids.size(); i++) {
            bool add = true;
            while (!s.empty()) {
                bool sign = asteroids[i] > 0;
                int top = s.top();
                bool topSign = top > 0;
                if (topSign == sign) {
                    break;
                } else if (topSign == false && sign == true) {
                    //asteroids moving away from each other
                    break;
                } else {
                    if (top > abs(asteroids[i])) {
                        add = false;
                        break;
                    } else if (top < abs(asteroids[i])) {
                        s.pop();
                    } else {
                        // top == asteroids[i]
                        s.pop();
                        add = false;
                        break;
                    }
                }
            }
            if (add) {
                s.push(asteroids[i]);
            }
        }

        std::vector<int> res(s.size());
        for (int i = s.size() - 1; i >= 0; i--) {
            res[i] = s.top();
            s.pop();
        }
        return res;
    }
};
