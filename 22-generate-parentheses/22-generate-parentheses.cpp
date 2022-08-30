class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, 0, 0, "", res);
        return res;
    }

        void generate(int n, int open, int closed, string s, vector<string>& res){
        if (open + closed > 2 * n)
            return;

        if (open == n && closed == n)
        {
            res.push_back(s);
            return;
        }


        if (closed < open) {
            generate(n, open, closed + 1, s + ")", res);
            generate(n, open + 1, closed, s + "(", res);

        }else{
            generate(n, open + 1, closed, s + "(", res);
        }
    }
};