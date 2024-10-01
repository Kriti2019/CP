class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
      int n = grid.size(); 
\t    int m = grid[0].size(); 
\t    // visited and distance matrix
\t    vector<vector<int>> vis(n, vector<int>(m, 0)); 
\t    vector<vector<int>> dist(n, vector<int>(m, 0)); 
\t    // <coordinates, steps>
\t    queue<pair<pair<int,int>, int>> q; 
\t    // traverse the matrix
\t    for(int i = 0;i<n;i++) {
\t        for(int j = 0;j<m;j++) {
\t            // start BFS if cell contains 1
\t            if(grid[i][j] == 0) {
\t                q.push({{i,j}, 0}); 
\t                vis[i][j] = 1; 
\t            }
\t            else {
\t                // mark unvisited 
\t                vis[i][j] = 0; 
\t            }
\t        }
\t    }
\t    
\t    int delrow[] = {-1, 0, +1, 0}; 
\t    int delcol[] = {0, +1, 0, -1}; 
\t    
\t    // traverse till queue becomes empty
\t    while(!q.empty()) {
\t        int row = q.front().first.first; 
\t        int col = q.front().first.second; 
\t        int steps = q.front().second; 
\t        q.pop(); 
\t        dist[row][col] = steps; 
\t        // for all 4 neighbours
\t        for(int i = 0;i<4;i++) {
\t            int nrow = row + delrow[i]; 
\t            int ncol = col + delcol[i]; 
\t            // check for valid unvisited cell
\t            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
\t            && vis[nrow][ncol] == 0) {
\t                vis[nrow][ncol] = 1; 
\t                q.push({{nrow, ncol}, steps+1});  
\t            }
\t        }
\t    }
\t    // return distance matrix
\t    return dist;    
    }
};