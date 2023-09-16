class Solution {
public:
    
    vector<vector<int>> dp;
    
    //dp solution
    int solve(int left, int right, string &s){
        int &ans = dp[left][right];
        if (ans != -1) return ans;
        if (left >= right) return 1;

        ans = 0;
        if (s[left] == s[right]) ans += solve(left + 1, right - 1, s);

        return ans;
    }
    
    //brute force solution
    bool isPali(int left, int right, string &s){
        while (left <= right && s[left] == s[right]){
            left++, right--;
        }
        return left >= right;
    }
    
    //optimized bf solution
    int optimized(int left, int right, string &s){
        int ctr = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]){
            ctr++; left--, right++;
        }
        return ctr;
    }
    
    int countSubstrings(string s) {
        //dp.resize(s.size(), vector<int>(s.size(), -1));
        int cnt = 0;
        // for (int i = 0; i < s.size(); i++){
        //     for (int j = i; j < s.size(); j++){
        //         //cnt += solve(i, j, s);
        //         //cnt += isPali(i, j, s);
        //     }
        // }
        for (int i = 0; i < s.size(); i++){
            cnt += optimized(i, i, s); //odd
            cnt += optimized(i, i + 1, s); //even
            
        }
        
        return cnt;
    }
};