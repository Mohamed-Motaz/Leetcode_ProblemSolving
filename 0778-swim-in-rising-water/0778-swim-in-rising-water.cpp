class Solution {
public:
    vector<vector<vector<int>>> dp;
    int n;
    
    bool ok(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    int solve(int x, int y, int cur, vector<vector<int>>& grid){
        if (x == n - 1 && y == n - 1){
            return cur;
        }
        
        int &ans = dp[x][y][cur];
        
        if (ans != -1) return ans;
        
        ans = INT32_MAX;
        if (ok(x, y - 1)){ //left
            ans = min(ans, solve(x, y - 1, max(cur, grid[x][y - 1]), grid));
        } 
        if (ok(x, y + 1)){ //right
            ans = min(ans, solve(x, y + 1, max(cur, grid[x][y + 1]), grid));
        } 
        if (ok(x - 1, y)){ //up
            ans = min(ans, solve(x - 1, y, max(cur, grid[x - 1][y]), grid));
        } 
        if (ok(x + 1, y)){ //down
            ans = min(ans, solve(x + 1, y, max(cur, grid[x + 1][y]), grid));
        } 
        return ans;
    }
    
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        dp.resize(n, vector<vector<int>>(n, vector<int>(50 * 50 + 1, -1)));
        
        return solve(0, 0, grid[0][0], grid);
        
    }
};