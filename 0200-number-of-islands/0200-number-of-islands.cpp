class Solution {
public:
    vector<vector<bool>> vis;
    int rows;
    int cols;

    // left up right down
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    bool isValid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        if (vis[x][y])
            return;
        vis[x][y] = 1;

        for (int i = 0; i < 4; i++)
        {
            int newX = x + dRow[i];
            int newY = y + dCol[i];
            if (isValid(newX, newY) && grid[newX][newY] == '1')
                dfs(grid, newX, newY);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        rows = grid.size();
        cols = grid[0].size();
        vis.resize(rows, vector<bool>(cols));
        int ctr = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                    dfs(grid, i, j), ctr++;
            }
        }
        return ctr;
    }
};