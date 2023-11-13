class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int idx, bool firstTaken, vector<int>& nums){
        if (idx >= nums.size())
            return 0;
        if (idx == nums.size() - 1 && firstTaken)
            return 0;
        
        int &ans = dp[idx][firstTaken];
        if (ans != -1)
            return ans;
        
        if (idx == 0){
            ans = max({
            solve(idx + 1, 0, nums), //leave
            solve(idx + 2, 1, nums) + nums[idx] //take
            });
        }
        else{
            ans = max({
            solve(idx + 1, firstTaken, nums), //leave
            solve(idx + 2, firstTaken, nums) + nums[idx] //take
            });
        }
        
        
        return ans;
    }
    
    int rob(vector<int>& nums) {
        dp.resize(nums.size(), vector<int>(2, -1));
        return solve(0, 0, nums);
    }
};