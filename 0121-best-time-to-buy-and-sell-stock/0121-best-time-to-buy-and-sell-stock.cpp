class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = INT32_MAX;
        int mx = 0;
        for (int e: prices){
            mn = min(mn, e);
            mx = max(mx, e - mn);
        }  
        return mx;
    }
};