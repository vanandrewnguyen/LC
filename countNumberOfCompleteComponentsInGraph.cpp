class Solution {
public:
    int solve(map<int,vector<int>> mp, vector<bool> &visited, int i){
        visited[i] = 1;
        queue<int> q;   
        q.push(i);
        set<int> bfs;

        // do bfs
        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            bfs.insert(curr);
            for (auto it : mp[curr]) {
                // loop through all connecting edges
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }

        // loop through every node in our local vertices group
        // if one has less or more edges than expected, IT IS NOT COMPLETE (or connects externally)
        int size = bfs.size();
        for (auto it : bfs) {
            if (mp[it].size() != size-1) {
                return 0;
            }
        }

        return 1;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // for undirected graph finds all completely connected notes in a graph
        // completely connected = full loop, cycles
        /*
A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
A connected component is said to be complete if there exists an edge between every pair of its vertices.
        */

        // map edge to edges
        map<int,vector<int>> mp;
        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            // undirected so push either direction
            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        vector<bool> visited(n, 0);
        int ans = 0;

        // Loop through unvisited vertices and solve
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int connected = solve(mp, visited, i);
                ans += connected;
            }
        }

        return ans;
    }
};
