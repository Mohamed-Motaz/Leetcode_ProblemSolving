class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool row0 = 0;
        bool col0 = 0;
        
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (!matrix[i][j]){
                    if (i == 0){
                        row0 = 1;
                    }
                    if (j == 0){
                        col0 = 1;
                    }
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        
        //loop on first element of all rows except
        //first one so as not to interfere with cols
        for (int i = 1; i < matrix.size(); i++){
            if (!matrix[i][0]){
                for (int j = 0; j < matrix[i].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        
        //loop on first element of all cols except
        //first one so as not to interfere
        for (int j = 1; j < matrix[0].size(); j++){
            if (!matrix[0][j]){
                for (int i = 0; i < matrix.size(); i++)
                    matrix[i][j] = 0;
            }
        }
        
        if (col0)
            for (int i = 0; i < matrix.size(); i++)
                matrix[i][0] = 0;
        if (row0)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
    
    }
};