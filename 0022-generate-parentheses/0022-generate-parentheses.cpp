
class Solution {
public:
    void work(vector<string>& res, int n, string cur, int open, int closed){
        if (open + closed == n * 2){
            if (open == closed)
                res.push_back(cur);
            return;
        }    
        if (open == closed){
            //must open
            work(res, n, cur + "(", open + 1, closed);
        }else{
            if (open < n)
                work(res, n, cur + "(", open + 1, closed);
            work(res, n, cur + ")", open, closed + 1);

        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        work(res, n, s, 0, 0);
        return res;
    }
};