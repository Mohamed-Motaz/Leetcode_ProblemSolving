class Trie{
public:
    vector<Trie*> children = vector<Trie*>(26, NULL);
    int end = 0;
};


void insert(Trie* root, string word){
    Trie* copy = root;
    for (char c: word){
        if (!copy->children[c - 'a'])
            copy->children[c - 'a'] = new Trie();
        
        copy = copy->children[c - 'a'];     
    }
    copy->end++;
}

class Solution {
public:

    int rows, cols;
    
    bool ok(int x, int y){
        return x >= 0 && x < rows && y >= 0 && y < cols;
    }
    
    //up down left right
    int dx[4] = {-1, 1, 0, 0}; 
    int dy[4] = {0, 0, -1, 1};
    
    void solve(Trie* root, int i, int j, string curWord, vector<vector<char>> &board, vector<string> &res){
        if (!ok(i, j) || board[i][j] == '#') return;
        if (!root->children[board[i][j] - 'a'])
            return;
        
        
        if (root->children[board[i][j] - 'a']->end)
        {
            res.push_back(curWord + board[i][j]);
            root->children[board[i][j] - 'a']->end--; //don't want to visit the same word multiple times
        }
        
        char c = board[i][j];
        board[i][j] = '#';
        
        
        solve(root->children[c - 'a'], i - 1, j, curWord + c, board, res);
        solve(root->children[c - 'a'], i + 1, j, curWord + c, board, res);
        solve(root->children[c - 'a'], i, j - 1, curWord + c, board, res);
        solve(root->children[c - 'a'], i, j + 1, curWord + c, board, res);
        
        
        board[i][j] = c;
        return;
    }
    
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        rows = board.size();
        cols = board[0].size();
        vector<string> res;
        
        Trie* root = new Trie();
        for (string &word: words){
            insert(root, word);
        }
        
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                solve(root, i, j, "", board, res);
            }
        }
        
        
        return res;
    }
};