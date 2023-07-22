class Solution {
public:
     int dp[302][302];
    
    bool solve(int idx, int prev, const string& s, const unordered_set<string> &st)
    {
        int len = idx - prev + 1;
        if (idx == s.size())
        {
            return st.find(s.substr(prev, len)) != st.end();
        }
        int &ans = dp[idx][prev];
        if (ans != -1)
            return ans;
        
        ans = 0;

        if (st.find(s.substr(prev, len)) != st.end())
        {
            ans |= solve(idx + 1, prev , s, st) || // ignore and go on
                    solve(idx + 1, idx + 1, s, st);          // take the word
        }
        else
        {
            ans |= solve(idx + 1, prev, s, st);
        }
        return ans;
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        memset(dp, -1, sizeof dp);
        unordered_set<string> st;
        for (string s : wordDict)
        {
            st.insert(s);
        }

        return solve(0, 0, s, st);
    }
};