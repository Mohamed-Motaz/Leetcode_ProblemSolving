class Solution {
public:
    vector<vector<int>> dp;
    int work(string &s, string &t, int sI, int tI)
    {
        if (tI == t.size()) // tI has indeed reached the end
            return 1;

        if (sI == s.size()) // sI has reached the end, but without tI as well
            return 0;

        int &ans = dp[sI][tI];
        if (ans != -1)
            return ans;
        ans = 0;
        if (s[sI] != t[tI])
        {
            // forced to leaved
            ans += work(s, t, sI + 1, tI);
        }
        else
        {
            ans += work(s, t, sI + 1, tI + 1) + // take
                   work(s, t, sI + 1, tI);      // leave
        }
        return ans;
    }
    int numDistinct(string s, string t)
    {
        const int n = s.size() + 1, m = t.size() + 1;
        dp.resize(n, vector<int>(m, -1));

        return work(s, t, 0, 0);
    }

};