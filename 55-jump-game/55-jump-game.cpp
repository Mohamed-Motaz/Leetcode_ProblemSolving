class Solution {
public:
    int dp[10004];

    bool solve(int idx, vector<int> &nums){
        if (idx == nums.size() - 1)
            return true;
        if (idx >= nums.size())
            return false;

        int &ans = dp[idx];
        if (ans != -1)
            return ans;

        ans = 0;

        for (int i = idx; i < nums.size() && i <= idx + nums[idx]; i++){
            ans += solve(i, nums);
            if (ans)
                return ans = true;
        }
        return ans = false;
    }

    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return solve(0, nums);
    }
};