class Solution {
public:
    int dp[102][3];

    int solve(int idx, bool take, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            return 0;
        }
        int &ans = dp[idx][take];
        if (ans != -1)
            return ans;

        ans = 0;

        if (take)
        {
            // have to leave
            ans = max(ans, solve(idx + 1, 0, nums));
        }
        else
        {
            // take or leave
            ans = max(
                nums[idx] + solve(idx + 1, 1, nums), // take
                solve(idx + 1, 0, nums));            // leave
        }

        return ans;
    }

    int rob(vector<int> &nums)
    {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, nums);
    }
};