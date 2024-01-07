class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int idx1, int idx2, string &s, string &p){
        if (idx2 == p.size() && idx1 == s.size())
            return 1;
        
        if (idx2 == p.size())
            return 0;
        //not the same case for idx1, because
        //remaining pattern in idx2 can still be valid ex: a*
        
        int &ans = dp[idx1][idx2];
        if (ans != -1)
            return ans;
        
        ans = 0;
        bool match = idx1 < s.size() && (s[idx1] == p[idx2] || p[idx2] == '.');
        if (idx2 + 1 < p.size() && p[idx2 + 1] == '*'){
            ans |= 
                solve(idx1, idx2 + 2, s, p) //ignore *
                ||
                (match && solve(idx1 + 1, idx2, s, p)); //use star
        }else if (match)
                ans |= solve(idx1 + 1, idx2 + 1, s, p);
            else 
                ans = 0;
        
        
        return ans;
    }
    
    bool isMatch(string s, string p) {
        dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        
        return solve(0, 0, s, p);
    }
};