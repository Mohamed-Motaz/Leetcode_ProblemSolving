class Solution {
public:
    int dp[25][2007];

    int solve(int curIdx, int curValue, vector<int> &nums, int target)
    {
        if (curIdx == nums.size())
        {
            return curValue == target;
        }

        int &ans = dp[curIdx][curValue + 1000];
        if (ans != -1)
            return ans;

        ans = solve(curIdx + 1, curValue + nums[curIdx], nums, target) +
              solve(curIdx + 1, curValue - nums[curIdx], nums, target);
        return ans;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, nums, target);
    }
};