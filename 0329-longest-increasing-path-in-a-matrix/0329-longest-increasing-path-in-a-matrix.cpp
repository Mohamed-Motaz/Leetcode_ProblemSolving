class Solution {
public:
    vector<vector<int>> vis;
    int ROWS;
    int COLS;
                //r l u d
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    int dfs(int x, int y, vector<vector<int>>& matrix){
        int &mx = vis[x][y];
        if (mx != -1)
            return vis[x][y];
        
        mx = 1;
        for (int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS &&
                matrix[newX][newY] > matrix[x][y]){
                mx = max(mx, dfs(newX, newY, matrix) + 1);
            }
        }
        vis[x][y] = mx;
        return mx;
    }
    
    int dfs_dp(vector<vector<int>>& matrix){
        int mx = 0;
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                for (auto &e: vis) e.clear(); 
                mx = max(mx, dfs(i, j, matrix));
            }
        }
        return mx;
    }
    
    int bfs_sol(vector<vector<int>>& matrix){
        return 0;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        vis.resize(ROWS, vector<int>(COLS, -1));
        return dfs_dp(matrix);
    }
};