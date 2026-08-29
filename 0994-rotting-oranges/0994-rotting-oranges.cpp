class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        
        // Step 1: Find all rotten and count fresh
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        
        int minutes = 0;
        
        // Directions: up, down, left, right
        int directions[4][2] = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };
        
        
        // Step 2: BFS
        while (!q.empty() && fresh > 0) {
            
            int size = q.size();
            
            // Process all rotten oranges of current minute
            while (size--) {
                
                auto [row, col] = q.front();
                q.pop();
                
                // Check 4 directions
                for (auto &dir : directions) {
                    
                    int newRow = row + dir[0];
                    int newCol = col + dir[1];
                    
                    // Check boundaries + fresh orange
                    if (newRow >= 0 && newRow < rows &&
                        newCol >= 0 && newCol < cols &&
                        grid[newRow][newCol] == 1) {
                        
                        // Make it rotten
                        grid[newRow][newCol] = 2;
                        
                        // Fresh orange decreased
                        fresh--;
                        
                        // Add newly rotten orange for next minute
                        q.push({newRow, newCol});
                    }
                }
            }
            
            minutes++;
        }
        
        
        // If fresh oranges still exist
        if (fresh > 0) {
            return -1;
        }
        
        return minutes;
    }
};