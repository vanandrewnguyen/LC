class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) { return true; }
        
        std::queue<int> q;
        std::vector<bool> visited(arr.size(), false);
        q.push(start);
    
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = true;

            std::cout << "Visiting " << curr << std::endl;

            if (arr[curr] == 0) return true;
            if (curr + arr[curr] < arr.size() && !visited[curr + arr[curr]]) { q.push(curr + arr[curr]); }
            if (curr - arr[curr] >= 0 && !visited[curr - arr[curr]]) { q.push(curr - arr[curr]); }

        }

        return false;
    }
};
