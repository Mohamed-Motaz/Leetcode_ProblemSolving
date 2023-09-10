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
        
        int prvRotten = 0; for (int i = 0; i < x; i++) for (int j = 0; j < y; j++) prvRotten += grid[i][j] == 2;
        int min = 1;
        while (true){
            
            for (int i = 0; i < x; i++){
                for (int j = 0; j < y; j++){
                    if (grid[i][j] == 2){
                        for (int a = 0; a < 4; a++){
                            int newX = i + dX[a];
                            int newY = j + dY[a];
                            if (ok(x, y, newX, newY) && grid[newX][newY] == 1) grid[newX][newY] = -2;
                        }
                    }
                }
            }
            
            
            
            
            
            int curRotten = 0;
            bool fresh = 0;
            for (int i = 0; i < x; i++){
                for (int j = 0; j < y; j++){
                    grid[i][j] = abs(grid[i][j]); //remove the neg
                    if (grid[i][j] == 2) curRotten++;
                    if (grid[i][j] == 1) fresh = 1;
                }
            }
            if (curRotten == prvRotten) {
                if (fresh) return -1;
                else return min - 1;
            }
            prvRotten = curRotten;
            ++min;
        }
        
        return -1;
        
    }
};