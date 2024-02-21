class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // sort points based on balloon width and make pairs of intervals
        // for every top on stack, check overlap with intervals
        // if overlap, change top, else add interval with stack (shoot the overlap)

        std::stack<std::pair<int, int>> s;
        std::vector<std::pair<int, int>> v;
        for (int i = 0; i < points.size(); i++) {
            v.push_back(std::make_pair(points[i][0], points[i][1]));
        }
        
        std::sort(points.begin(), points.end());
        s.push(v[0]);

        for (int i = 1; i < v.size(); i++) {
            std::pair<int, int> t = s.top();
            if (t.second >= v[i].first) {
                // overlap found
                s.pop();
                s.push(std::make_pair(v[i].first, min(v[i].second, t.second)));
            } else {
                s.push(v[i]);
                // if no overlap, push the disjointed interval
            }
        }
        return s.size();
    }
};
