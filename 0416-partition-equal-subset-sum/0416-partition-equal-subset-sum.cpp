class Solution {
public:
    int dp[201][100 * 200 + 2];

    bool solve(int idx, int curSum, int totSum, vector<int> &nums)
    {
        if (idx == nums.size())
            return curSum == totSum;

        if (curSum > totSum)
            return 0;

        int &ans = dp[idx][curSum];
        if (ans != -1)
            return ans;

        ans = solve(idx + 1, curSum, totSum, nums) ||           // leave
              solve(idx + 1, curSum + nums[idx], totSum, nums); // take

        return ans;
    }

    bool canPartition(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        int totSum = 0;
        for (int e : nums)
            totSum += e;
        if (totSum % 2)
            return 0;

        return solve(0, 0, totSum / 2, nums);
    }
};