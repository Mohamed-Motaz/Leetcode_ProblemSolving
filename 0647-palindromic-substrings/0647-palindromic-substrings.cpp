class Solution {
public:
    
    vector<vector<int>> dp;
    
    //dp solution
    int solve(int left, int right, string &s){
        if (left >= right) return 1;
        int &ans = dp[left][right];
        if (ans != -1) return ans;
        ans = 0;
        if (s[left] == s[right]) ans += solve(left + 1, right - 1, s);

        return ans;
    }
    
    
    int countSubstrings(string s) {
        dp.resize(s.size(), vector<int>(s.size(), -1));
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            for (int j = i; j < s.size(); j++){
                cnt += solve(i, j, s);
            }
        }
        
        return cnt;
    }
};