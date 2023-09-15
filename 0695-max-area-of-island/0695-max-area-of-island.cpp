class Solution {
public:
    int ROWS = 0;
    int COLS = 0;
    
    vector<vector<bool>> vis;
    
    bool within(int x, int y){
        return (x >= 0 && x < ROWS) && (y >= 0 && y < COLS);
    }
    
    int dfs(int x, int y, vector<vector<int>>& grid){
        if (!within(x, y) || vis[x][y] || grid[x][y] == 0)
            return 0;
        
        vis[x][y] = 1;
        int ans = 1;
        
        ans += dfs(x - 1, y, grid);
        ans += dfs(x + 1, y, grid);
        ans += dfs(x, y + 1, grid);
        ans += dfs(x, y - 1, grid);
            
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        vis.resize(ROWS, vector<bool>(COLS));
        int mx = 0;
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                if (grid[i][j] == 1){
                    mx = max(mx, dfs(i, j, grid));
                }
            }
        }
        return mx;
    }
};