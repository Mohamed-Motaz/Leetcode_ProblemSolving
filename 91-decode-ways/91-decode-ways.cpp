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
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == '0') dp[i] = 0;
            else{
                dp[i] += dp[i + 1];
                if (i + 1 < s.size() && ((s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))){
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};