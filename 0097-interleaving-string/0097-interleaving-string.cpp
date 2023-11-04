class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int a, int b, string &s1, string &s2, string &s3){
        if (a + b == s3.size())
            return 1;

        
        int &ans = dp[a][b];
        if (ans != -1)
            return ans;
        
        ans = 0;
        if (a < s1.size() && s3[a + b] == s1[a])
            ans |= solve(a + 1, b, s1, s2, s3);
        if (b < s2.size() && s3[a + b] == s2[b])
            ans |= solve(a, b + 1, s1, s2, s3);
        
        if ((a < s1.size() && s3[a + b] != s1[a]) && (b < s2.size() && s3[a + b] != s2[b]))
            ans = 0;
        return ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        if (s1.size() + s2.size() != s3.size()) return 0;
        return solve(0, 0, s1, s2, s3);
    }
};