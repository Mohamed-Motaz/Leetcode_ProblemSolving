class Solution {
public:
    int rows;
    int cols;

    // left up right down
    int dRow[4] = {0, -1, 0, 1};
    int dCol[4] = {-1, 0, 1, 0};

    bool isValid(int i, int j)
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }

    bool dfs(vector<vector<char>> &board, string &word, int x, int y, int curIdx)
    {
        if (curIdx == word.size())
            return true;

        bool ans = false;
        char tmp = board[x][y];
        board[x][y] = '#'; // prevent any of my children from coming back to me
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dRow[i];
            int newY = y + dCol[i];
            if (isValid(newX, newY) && board[newX][newY] == word[curIdx])
                ans |= dfs(board, word, newX, newY, curIdx + 1);
        }
        board[x][y] = tmp;
        return ans;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (board[i][j] == word[0])
                {

                    if (dfs(board, word, i, j, 1))
                        return true;
                }
            }
        }
        return false;
    }
};