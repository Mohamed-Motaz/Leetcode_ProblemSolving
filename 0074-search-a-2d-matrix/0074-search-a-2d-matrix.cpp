class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      int s = 0, e = matrix.size() - 1, m = -1;
        int row = -1;
        while (s <= e)
        {
            m = (s + e) / 2;
            if (target < matrix[m][0])
            {
                e = m - 1;
            }
            else
            {
                row = m;
                s = m + 1;
            }
        }
        
        if (row == -1)
            return false;

        s = 0, e = matrix[row].size() - 1, m = -1;
        while (s <= e)
        {
            m = (s + e) / 2;
            if (target < matrix[row][m])
            {
                e = m - 1;
            }
            else if (target > matrix[row][m])
            {
                s = m + 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};