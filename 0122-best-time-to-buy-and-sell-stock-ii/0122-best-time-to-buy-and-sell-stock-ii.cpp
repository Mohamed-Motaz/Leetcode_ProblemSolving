class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int idx, bool canSell, vector<int>& prices){
        if (idx == prices.size())
            return 0;
        
        int &ans = dp[idx][canSell];
        if (ans != -1)
            return ans;

        ans = 0;
        if (!canSell)
            ans = max({
                ans, 
                solve(idx + 1, 0, prices), //ignore
                solve(idx + 1, 1, prices) - prices[idx] //buy
                });
        else{
            ans = max({
                        ans,
                     solve(idx + 1, 0, prices) + prices[idx], //sell
                     solve(idx + 1, 1, prices) //keep
                       });
        }
        
        
        return ans;
    }
    
    
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(), vector<int>(2, -1));
        return solve(0, 0, prices);
    }
    
    
//     vector<vector<int>> dp;
//     int solve(int idx, bool canSell, vector<int>& prices){
//         if (idx == prices.size())
//             return 0;
        
//         int &ans = dp[idx][canSell];
//         if (ans != -1)
//             return ans;
        
        
//     }
    
    
//     int maxProfit(vector<int>& prices) {
//         dp.resize(prices.size(), vector<int>(2, -1));
//         return solve(0, 0);
//     }
};