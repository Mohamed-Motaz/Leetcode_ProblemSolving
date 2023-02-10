void doWork(vector<string> &v, int n, int op, int cl, string s)
{
    if (op == n && cl == n)
    {            
        v.push_back(s);
        return;
    }

    if (op < n) doWork(v, n, op + 1, cl, s + '(');
    if (op > cl) doWork(v, n, op, cl + 1, s + ')');
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        doWork(res, n, 0, 0, "");
        return res;
    }
};