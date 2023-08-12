class Solution {
public:
    vector<vector<int>> dp;
    const int OUT = 2506;
    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(2507, -1));
        return solve(0, OUT, nums);
    }
    
    int solve(int cur, int prev, vector<int> &nums){
        if (cur == nums.size())
            return 0;
        
        int &ans = dp[cur][prev];
        if (ans != -1) return ans;
        
        ans = 0;
        
        if (prev == OUT){
            ans = solve(cur + 1, cur, nums) + 1;
        }
        else if (nums[cur] > nums[prev]){
            ans = solve(cur + 1, cur, nums) + 1;
        }
        
        ans = max(ans, solve(cur + 1, prev, nums));
        return ans;
    }
};