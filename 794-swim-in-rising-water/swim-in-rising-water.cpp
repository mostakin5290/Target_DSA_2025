class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // Min-heap: (max_elevation_so_far, row, col)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        // Distance array: stores the minimum max elevation to reach each cell
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        // Directions: up, right, down, left
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        // Start from top-left
        pq.push({grid[0][0], 0, 0});
        dist[0][0] = grid[0][0];
        
        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            int currentMax = current[0];
            int row = current[1];
            int col = current[2];
            
            // If we reached the destination
            if (row == n - 1 && col == n - 1) {
                return currentMax;
            }
            
            // If we found a better path to this cell, skip
            if (currentMax > dist[row][col]) {
                continue;
            }
            
            // Explore neighbors
            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                    // The max elevation on path to reach new cell
                    int newMax = max(currentMax, grid[newRow][newCol]);
                    
                    // If we found a better path to the neighbor
                    if (newMax < dist[newRow][newCol]) {
                        dist[newRow][newCol] = newMax;
                        pq.push({newMax, newRow, newCol});
                    }
                }
            }
        }
        
        return dist[n-1][n-1];
    }
};