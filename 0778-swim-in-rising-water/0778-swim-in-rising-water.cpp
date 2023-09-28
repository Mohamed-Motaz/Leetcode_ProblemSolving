class Solution {
public:
    vector<vector<int>> dp;
    int n;
    
    bool ok(int x, int y){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    
    int memodp(int x, int y, int cur, vector<vector<int>>& grid){
        if (x == n - 1 && y == n - 1){
            return cur;
        }
        
        int &ans = dp[x][y];
        
        if (ans != -1) return ans;
        
        ans = INT32_MAX;
        if (ok(x, y - 1)){ //left
            ans = min(ans, memodp(x, y - 1, max(cur, grid[x][y - 1]), grid));
        } 
        if (ok(x, y + 1)){ //right
            ans = min(ans, memodp(x, y + 1, max(cur, grid[x][y + 1]), grid));
        } 
        if (ok(x - 1, y)){ //up
            ans = min(ans, memodp(x - 1, y, max(cur, grid[x - 1][y]), grid));
        } 
        if (ok(x + 1, y)){ //down
            ans = min(ans, memodp(x + 1, y, max(cur, grid[x + 1][y]), grid));
        } 
        return ans;
    }
    
    vector<vector<bool>> vis;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    
    
    int bfs(vector<vector<int>> &grid){
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0});
        
        while (pq.size()){
            vector<int> cur = pq.top();
            pq.pop();
            
            if (cur[1] == n - 1 && cur[2] == n - 1)
                return cur[0];
            
            for (int i = 0; i < 4; i++){
                int newX = cur[1] + dx[i];
                int newY = cur[2] + dy[i];
                if (ok(newX, newY) && !vis[newX][newY]){
                    pq.push({max(cur[0], grid[newX][newY]), newX, newY});
                    vis[newX][newY] = 1;
                }
            }
            
        }
        return -1;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        
        //dp.resize(n, vector<vector<int>>(n, vector<int>(50 * 50 + 1, -1)));
        //return memodp(0, 0, grid[0][0], grid);
        
        vis.resize(n, vector<bool>(n, 0));
        return bfs(grid);
        
    }
};