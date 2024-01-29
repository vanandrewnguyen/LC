/*
https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
Follow the below steps to implement the above approach:

Iterate over all the nodes of the graph and Keep a visited array visited[] to track the visited nodes.
Run a Depth First Traversal on the given subgraph connected to the current node and pass the parent of the current node. In each recursive 
Set visited[root] as 1.
Iterate over all adjacent nodes of the current node in the adjacency list 
If it is not visited then run DFS on that node and return true if it returns true.
Else if the adjacent node is visited and not the parent of the current node then return true.
Return false.
*/

class Solution {
public:
    bool checkCycle(int index, std::vector<vector<int>>& adj, std::vector<bool> &visited, std::vector<bool>& dfsVisited) {
        visited[index] = true;
        dfsVisited[index] = true;
        for (std::vector<int>::iterator it = adj[index].begin(); it != adj[index].end(); it++) {
            // Loop through prereq for current node
            if (!visited[*it]) {
                if (checkCycle(*it, adj, visited, dfsVisited)) {
                    // If not visited but we have checked for a cycle, return it HAS a cycle
                    return true;
                }
            } else if (visited[*it] && dfsVisited[*it]) {
                // has cycle if visited already 
                return true;
            }
        }

        // dfs visited only turned off after recursion, since we'll know for this node there is no cycle
        dfsVisited[index] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prereq -> [a, b] where you must do a before b
        // make adjacency matrix of graph and check for cycles (cycle = impossible loop)

        std::vector<vector<int>> adjacency(numCourses);
        for (std::vector<vector<int>>::iterator it = prerequisites.begin(); it != prerequisites.end(); it++) {
            adjacency[(*it)[1]].push_back((*it)[0]); // for course b, it has prereq a
        }

        std::vector<bool> visited(numCourses, false);
        std::vector<bool> dfsVisited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && checkCycle(i, adjacency, visited, dfsVisited)) {
                return false;
            }
        }
        return true;
    }
};
