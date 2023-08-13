class Solution {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        int ans = 0;
        dp.resize(nums.size(), 1);
        
        for (int i = 0; i < nums.size(); i++){
            for (int j = 0; j < i; j++){
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
    
    
};