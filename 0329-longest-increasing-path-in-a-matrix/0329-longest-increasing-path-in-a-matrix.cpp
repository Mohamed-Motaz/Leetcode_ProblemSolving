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
    
    int top_sort_kahn_algo(vector<vector<int>>& matrix){
        //start with all the leaves, and then move 1 by one to remove them
        vector<vector<int>> inDegree(ROWS, vector<int>(COLS, 0));
        for (int i = 0; i < ROWS; i++){
            for (int j = 0; j < COLS; j++){
                for (int k = 0; k < 4; k++){
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS &&
                        matrix[i][j] > matrix[newX][newY]){
                        inDegree[i][j]++;
                    }
                }
            }
        }
        
        queue<pair<int, int>> q;
        for (int i = 0; i < ROWS; i++) 
            for (int j = 0; j < COLS; j++) 
                if (!inDegree[i][j]) q.push(make_pair(i, j));
        
        int path = 0;
        while (q.size()){
            int sz = q.size();
            for (int i = 0; i < sz; i++){
                pair<int, int> p = q.front();
                q.pop();
                for (int k = 0; k < 4; k++){
                    int newX = p.first + dx[k];
                    int newY = p.second + dy[k];
                    if (newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS &&
                        matrix[newX][newY] > matrix[p.first][p.second]){
                        inDegree[newX][newY]--;
                        if (!inDegree[newX][newY])
                            q.push(make_pair(newX, newY));
                    }
                    
                }
            }
            path++;
        }
        return path;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        ROWS = matrix.size();
        COLS = matrix[0].size();
        // vis.resize(ROWS, vector<int>(COLS, -1));
        // return dfs_dp(matrix);
        return top_sort_kahn_algo(matrix);
    }
};