class Solution {
public:
    vector<vector<bool>> vis;
    vector<int> res;
    bool ok(int newX, int newY, vector<vector<int>>& matrix){
        return newX >= 0 && newX < matrix.size() && 
            newY >= 0 && newY < matrix[0].size() && 
            !vis[newX][newY];
    }
    
    void dfs(int x, int y, int prev, vector<vector<int>>& matrix){
        if (!ok(x, y, matrix))    
            return;
        vis[x][y] = 1;
        res.push_back(matrix[x][y]);
        
        //prioritize same path
        if (prev == 0) dfs(x, y + 1, prev, matrix);
        if (prev == 1) dfs(x + 1, y, prev, matrix);
        if (prev == 2) dfs(x, y - 1, prev, matrix);
        if (prev == 3) dfs(x - 1, y, prev, matrix);
        
        //else just keep going if can't go to the same path
        dfs(x, y + 1, (prev + 1) % 4, matrix);
        dfs(x + 1, y, (prev + 1) % 4, matrix);
        dfs(x, y - 1, (prev + 1) % 4, matrix);
        dfs(x - 1, y, (prev + 1) % 4, matrix);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vis.resize(matrix.size(), vector<bool>(matrix[0].size()));
        dfs(0, 0, 0, matrix);
        return res;
    }
};