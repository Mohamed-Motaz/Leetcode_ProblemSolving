class Solution {
public:
    vector<vector<long long>> dp;
    long long solve(int idx, int cur, int target, vector<int>&nums){
        if (idx == nums.size())
            return cur == target ? 0 : INT32_MIN;
        long long &ans = dp[idx][cur];
        if (ans != -1) return ans;
        ans = INT32_MIN;
        
        ans = max(ans, solve(idx + 1, cur, target, nums));
        if (cur + nums[idx] <= target){
            ans = max(ans, solve(idx + 1, cur + nums[idx], target, nums) + 1);
        }
        return ans;
    }
    
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.resize(nums.size() + 1, vector<long long>(1001, -1));
        
        int ans = solve(0, 0, target, nums);
        return ans <= 0 ? -1 : ans;
    }
};