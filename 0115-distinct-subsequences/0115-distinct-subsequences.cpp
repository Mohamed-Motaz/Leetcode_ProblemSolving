class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, string &s, string &t){
        if (j == t.size()){
            return 1;
        }
        if (i == s.size())
            return 0;
        
        int &ans = dp[i][j];
        if (ans != -1)
            return ans;
        
        ans = solve(i + 1, j, s, t); //leave the current s char
        
        if (s[i] == t[j])
            ans += solve(i + 1, j + 1, s, t);
        
        return ans;
        
    }
    
    int numDistinct(string s, string t) {
        dp.resize(s.size(), vector<int>(t.size(), -1));
        return solve(0, 0, s, t);
    }
};