class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int rows = matrix.size(), cols = matrix[0].size();
        int top = 0, left = 0, right = cols - 1, bottom = rows - 1;
        vector<int> res;
        
        while (top <= bottom && left <= right){
            for (int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }    
            ++top;
            
            for (int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            --right;
            
            if (top > bottom)
                break;
            
            for (int i = right; i >= left; i--){
                res.push_back(matrix[bottom][i]);
            }
            --bottom;
            
            if (left > right)
                break;
            
            for (int i = bottom; i >= top; i--){
                res.push_back(matrix[i][left]);
            }
            ++left;
        }
        
        return res;
    }
};