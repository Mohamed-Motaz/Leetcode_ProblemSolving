class Solution {
public:
    
    vector<vector<int>> dp;
    int solve(int cur, int prev, vector<int>& nums){
        if (cur == nums.size())
            return 0;
        
        int &ans = dp[cur][prev];
        if (ans != -1)
            return ans;
        
        ans = 0;
        
        if (prev == nums.size())
            ans = max(ans, solve(cur + 1, cur, nums) + 1);
        else if (nums[cur] > nums[prev])
            ans = max(ans, solve(cur + 1, cur, nums) + 1);
        
        //leave
        ans = max(ans, solve(cur + 1, prev, nums));
    
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size() + 1, vector<int>(nums.size() + 1, -1));
        return solve(0, nums.size(), nums);;
    }
};