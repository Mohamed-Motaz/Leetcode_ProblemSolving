class Solution {
public:
    int dp[301][5001];
vector<int> v;

int solve(int idx, int sum, int target)
{
    if (idx == v.size())
    {
        return sum == target;
    }

    int &ans = dp[idx][sum];
    if (ans != -1)
        return ans;

    ans = 0;
    if (sum + v[idx] <= target)
    {
        // take
        ans += solve(idx, sum + v[idx], target);
        // leave
        ans += solve(idx + 1, sum, target);
    }
    else
    {
        // have to leave
        ans += solve(idx + 1, sum, target);
    }
    return ans;
}

int change(int amount, vector<int> &coins)
{
    memset(dp, -1, sizeof dp);
    v = coins;
    return solve(0, 0, amount);
}
};