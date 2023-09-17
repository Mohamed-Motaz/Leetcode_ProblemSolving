class Solution {
public:
    vector<vector<int>> dp;
    int rows, cols;
    
    int solve(int x, int y){
        if (x >= rows || y >= cols) return 0;
        if (x == rows - 1 && y == cols - 1) return 1;
        int &ans = dp[x][y];
        if (ans != -1) return ans;
        ans = 0;
        ans += solve(x + 1, y) + solve(x, y + 1);
        return ans;
    }
    
    int uniquePaths(int m, int n) {
        //dp.resize(m, vector<int>(n, -1));
        //rows = m, cols = n;
        //return solve(0, 0);
        
        dp.resize(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};