class Solution {
public:
    
    unordered_set<int> posDiagonal;
    unordered_set<int> negDiagonal;
    unordered_set<int> cols;
    vector<vector<string>> sol;
    
    
    
    void solve(int row, int n, vector<string>& board){
        if (n == row){
            sol.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++){
            int pos = row + col;
            int neg = col - row; //or row - col
            if (cols.find(col) != cols.end() ||
                posDiagonal.find(pos) != posDiagonal.end() ||
               negDiagonal.find(neg) != negDiagonal.end()){
                continue;
            }
            cols.insert(col);
            posDiagonal.insert(pos);
            negDiagonal.insert(neg);
            board[row][col] = 'Q';
            
            solve(row + 1, n, board);
            
            cols.erase(col);
            posDiagonal.erase(pos);
            negDiagonal.erase(neg);
            board[row][col] = '.';
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board = vector<string>(n, string(n, '.'));
        solve(0, n, board);
        return sol;
    }
};