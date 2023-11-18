class Solution {
public:
    
    vector<int> dp;
    const int MOD = 1e9 + 7;
    int solve(int i, string &s){
        if (i == s.size())
            return 0;
        
        int &ans = dp[i];
        if (ans != -1)
            return ans;
        ans = 0;
        
        vector<bool> vis(26);
        for (int x = i; x < s.size(); x++){
            if (vis[s[x] - 'a'])
                continue;
            vis[s[x] - 'a'] = 1;
            ans += (solve(x + 1, s) + 1) % MOD;
            ans %= MOD;
        }
        return ans;
    }
    
    int distinctSubseqII(string s) {
        dp.resize(s.size(), -1);
        return solve(0, s);
    }
};