class Solution {
public:
    vector<vector<bool>> pacific, atlantic;
    int n;
    int m;

    // up down left right
    int dRow[4] = {-1, 1, 0, 0};
    int dCol[4] = {0, 0, -1, 1};

    bool isValid(int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    void dfs(vector<vector<int>> &heights, int x, int y, vector<vector<bool>> &vis)
    {
        if (vis[x][y])
            return;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dRow[i], newY = y + dCol[i];
            if (isValid(newX, newY) && heights[x][y] <= heights[newX][newY]) //check all the points that can reach the pacific ocean. not pacific ocean --> point, but point --> pacific ocean
                dfs(heights, newX, newY, vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        n = heights.size(), m = heights[0].size();
        pacific.resize(n, vector<bool>(m));
        atlantic.resize(n, vector<bool>(m));
    
        for (int i = 0; i < n; i++)
        {
            // left pacific
            dfs(heights, i, 0, pacific);

            // right atlantic
            dfs(heights, i, m - 1, atlantic);
        }

        for (int i = 0; i < m; i++)
        {
            // up pacific
            dfs(heights, 0, i, pacific);
            // down atlantic
            dfs(heights, n - 1, i, atlantic);
        }

        vector<vector<int>> res;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                if (atlantic[i][j] && pacific[i][j])
                    res.push_back({i, j});
        }
        return res;
    }

};