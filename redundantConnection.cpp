// https://www.youtube.com/watch?v=ayW5B2W9hfo

class Solution {
public:
    // union find ds
    std::vector<int> parent;
    std::vector<int> rank;

    int find(int i) {
        // tree structure always return representative of group through parent traversal
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    void join(int u, int v) {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV) {
            // Union by rank to balance trees
            if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
            else if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        
        // Initialize each node as its own parent
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            // if the parent matches they belong to the same group (union find ds)
            if (find(u) == find(v)) return edge; // Cycle detected!
            join(u, v); // Merge sets
        }
        
        return {};
    }
};



/*
This solution does not work because we need the last occurance of a redundant edge -> see test case 2, it contains 4 possible redundant edges...
bfs/dfs could return ANY of the solutions

a brute force solution would be to loop through EVERY edge, run dfs and check for cycles, if so, add the currEdge into a list
then sort the list and return the last redundant edge

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // write an algo that removes a redundant edge...
        // so we could choose one vertex, then form a MST from the graph, then find the remaining edge
        // and then remove it... I guess the problem guarantees such edge should always exist

        // kruskals work on weighted, perhaps we can just use bfs 

        // grab all vertices... into a set (no dupes)
        std::set<int> verts;
        for (int i = 0; i < edges.size(); i++) {
            verts.insert(edges[i][0]); 
            verts.insert(edges[i][1]); 
        }

        std::vector<std::vector<int>> copyEdges = edges;
        std::queue<int> q;
        std::vector<bool> visited(verts.size(), false);

        int source = *(verts.begin());
        q.push(source);
        visited[source] = true;

        // do bfs
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            std::cout << "Visited node " << curr << std::endl;
         
            // get neighbours
            for (std::vector<int>& edge : edges) {
                if (edge[0] == curr) {
                    if (!visited[edge[1]]) {
                        visited[edge[1]] = true;
                        q.push(edge[1]);
                        
                        std::vector<std::vector<int>>::iterator pos = std::find(copyEdges.begin(), copyEdges.end(), edge);
                        if (pos != copyEdges.end()) { copyEdges.erase(pos); }
                    }
                }
            }
        }

        return *(copyEdges.begin());
    }
};
*/
