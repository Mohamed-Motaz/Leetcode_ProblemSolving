class Solution {
public:
                //up down left right
    int dX[4] = {-1, 1,  0, 0};
    int dY[4] = {0 , 0, -1, 1};
    
    bool ok(int row, int col, int newX, int newY){
        return newX >= 0 && newX < row && newY >= 0 && newY < col;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int x = grid.size();
        int y = grid[0].size();
        
        queue<pair<int, int>> q;

        int fresh = 0;
        for (int i = 0; i < x; i++) 
            for (int j = 0; j < y; j++) 
                if (grid[i][j] == 2) q.push(make_pair(i, j));
                else if (grid[i][j] == 1) fresh++;
        if (!fresh) return 0;
        
        int curMin = 1;
        while (q.size()){
            int n = q.size();
            for (int i = 0; i < n; i++){
                pair<int, int> p = q.front(); q.pop();
                
                for (int i = 0; i < 4; i++){
                    int newX = p.first + dX[i];
                    int newY = p.second + dY[i];
                    if (ok(x, y, newX, newY) && grid[newX][newY] == 1){
                        fresh--;
                        grid[newX][newY] = 2;
                        q.push(make_pair(newX, newY));
                    }
                }
            }
            if (!fresh) return curMin;
            curMin++;
        }
        return -1;
        
    }
};