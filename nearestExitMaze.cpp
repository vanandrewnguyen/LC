struct Node{
    int x , y , dist;
};

class Solution {
public:
    bool isValid(vector <vector <char>> &arr , vector <vector <bool>> &vis , int i , int j , int m , int n) {
        if (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j] and arr[i][j] == '.'){
            return true;
        }
        return false;
    }
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // get source, push in queue, while queue is not empty, remove top element
        // (bfs) store dist i, j, check if location and put in neighbouring cells

        int n = maze.size();
        int m = maze[0].size();
        std::vector<std::vector <bool>> vis(n, std::vector<bool>(m, false));
        int dx[] = {1 , 0 , -1 , 0};
        int dy[] = {0 , 1 , 0 , -1}; // change in dir

        int x = entrance[0];
        int y = entrance[1];
        
        std::queue<Node> q;
        int min_dist = 1e9;
        q.push({x, y, 0});
        vis[x][y] = true;

        while (!q.empty()) {
            Node cur = q.front();
            q.pop();
            int i = cur.x;
            int j = cur.y;
            int dist = cur.dist;
            if (((i == 0 || i == n - 1) || (j == 0 || j == m - 1)) && maze[i][j] == '.') {
                if (i != x || j != y){
                    min_dist = dist;
                    break;
                }
            }

            int neighbours = 4;
            for (int k = 0; k < neighbours; k++){
                int ti = i + dx[k] , tj = j + dy[k];
                if (isValid(maze, vis, ti, tj, m, n)){
                    vis[ti][tj] = true;
                    q.push({ti, tj, dist + 1});
                    
                }
            }
        }

        if (min_dist == 1e9) {
            return -1;
        }
        return min_dist;
    }
};
