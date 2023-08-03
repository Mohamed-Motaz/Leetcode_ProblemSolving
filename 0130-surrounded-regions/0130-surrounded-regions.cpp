class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    vector<vector<bool>> vis;

    bool ok(int x, int y, vector<vector<char>> &board)
    {
        return x < vis.size() && y < vis[0].size() && !vis[x][y] && board[x][y] == 'O';
    }

    void dfs(int x, int y, vector<vector<char>> &board)
    {
        if (vis[x][y])
            return;

        vis[x][y] = 1;
        board[x][y] = '-';

        for (int i = 0; i < 4; i++)
        {
            int newX = x + row[i];
            int newY = y + col[i];
            if (ok(newX, newY, board))
                dfs(newX, newY, board);
        }
    }

    void solve(vector<vector<char>> &board)
    {
        const int row = board.size();
        const int col = board[0].size();
        vis.resize(row, vector<bool>(col));

        for (int i = 0; i < row; i++)
        {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
            if (board[i][col - 1] == 'O')
                dfs(i, col - 1, board);
        }
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 'O')
                dfs(0, i, board);
            if (board[row - 1][i] == 'O')
                dfs(row - 1, i, board);
        }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                board[i][j] == '-' ? board[i][j] = 'O' : board[i][j] = 'X';
    }
};