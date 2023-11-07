class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int idx, bool canBuy, vector<int>& prices){
        if (idx >= prices.size())
            return 0;
        int &ans = dp[idx][canBuy];
        if (ans != -1)
            return ans;
        ans = 0;
        
        ans = solve(idx + 1, canBuy, prices);
        
        if (canBuy)
            ans = max(ans, -prices[idx] + solve(idx + 1, 0, prices));
        else
            ans = max(ans, prices[idx] + solve(idx + 2, 1, prices));
        
        return ans;
    }
    
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size() + 5, vector<int>(2, -1));
        return solve(0, 1, prices);
    }
};