class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = 0, e = matrix.size() - 1, m = -1;

        while (s <= e){
            m = (s + e) / 2;
            vector<int> v = matrix[m];
            if (v[0] > target)
                e = m - 1;
            else if (v.back() < target)
                s = m + 1;
            else{
                int ss = 0, ee = v.size() - 1, mm = -1;
                while (ss <= ee){
                    mm = (ss + ee) / 2;
                    if (v[mm] > target)
                        ee = mm - 1;
                    else if (v[mm] < target)
                        ss = mm + 1;
                    else
                        return true;
                }
                return false;
            }
        }

        return false;
    }
};