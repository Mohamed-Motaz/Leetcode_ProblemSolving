class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int mn = INT32_MAX;
        for (int i = 0; i < prices.size(); i++){
            res = max(res, prices[i] - mn);
            mn = min(mn, prices[i]);
        }
        return res;
    }
};