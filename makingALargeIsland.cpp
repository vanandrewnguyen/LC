class Solution {
public:
    /*
    there exists some islands of variable size
    flip ONE 0->1 to get the maximal island size
    we could label existing islands, using bfs, store each size in a map
    for each 0, check neighbours, if 1, then island exists, then add size to island (keep visited)
    track maximum island size
    edge case: if no 0, then return maximum island size, if no 1, return 1 (since we place a 1)
    */
    
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int gridSize = grid.size();
        std::vector<std::vector<int>> labels(gridSize, std::vector<int>(gridSize, 0));
        std::unordered_map<int, int> islandSize;
        int label = 1; // id of island
        int maxSize = 0;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[i][j] == 1 && labels[i][j] == 0) {
                    // if we are on land, and have not flipped this cell
                    int size = 0;
                    std::vector<std::pair<int, int>> stack;
                    stack.push_back(std::make_pair(i, j));
                    labels[i][j] = label;

                    // now do bfs to search island and determine size
                    while (!stack.empty()) {
                        auto [x, y] = stack.back();
                        stack.pop_back();
                        size++;

                        for (auto [dx, dy] : directions) {
                            // for each dir check if touching island and not visited
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize &&
                                grid[nx][ny] == 1 && labels[nx][ny] == 0) {
                                labels[nx][ny] = label;
                                stack.push_back(std::make_pair(nx, ny));
                            }
                        }
                    }

                    islandSize[label] = size;
                    maxSize = std::max(maxSize, size);
                    label++;
                }
            }
        }

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                if (grid[i][j] == 0) {
                    std::unordered_set<int> neighbourLabels;
                    int total = 1;

                    // for each water cell, if there exists some land next to it, check if we connect multiple islands
                    // and for each island, then we know the label, and hence we sum the label->size from unordered_map
                    for (auto [dx, dy] : directions) {
                        int nx = i + dx;
                        int ny = j + dy;

                        if (nx >= 0 && nx < gridSize && ny >= 0 && ny < gridSize &&
                            grid[nx][ny] == 1) {
                            neighbourLabels.insert(labels[nx][ny]);
                        }
                    }

                    for (int id : neighbourLabels) {
                        total += islandSize[id];
                    }
                    maxSize = std::max(maxSize, total);
                }
            }
        }


        return maxSize;
    }
};







