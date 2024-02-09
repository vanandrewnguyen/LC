class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        std::vector<int> heights;
        heights.push_back(0);
        for (int i = 0; i < gain.size(); i++) {
            heights.push_back(heights.back() + gain[i]);
        }

        std::sort(heights.begin(), heights.end());
        return heights.back();
    }
};
