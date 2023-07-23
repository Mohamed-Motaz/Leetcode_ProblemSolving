class Solution {
public:
    int dp[101];
    string ss;
    int solve(int idx)
    {
        if (idx == ss.size())
            return 1;

        int &ans = dp[idx];
        if (ans != -1)
            return ans;
        
        if (ss[idx] == '0')
            return ans = 0;

        

        ans = solve(idx + 1);

        if (idx + 1 < ss.size() && ((ss[idx] == '1' || (ss[idx] == '2' && ss[idx + 1] <= '6'))))
            ans += solve(idx + 2);

        return ans;
    }

    int numDecodings(string s)
    {
        memset(dp, -1, sizeof dp);
        ss = s;
        return solve(0);
    }
};