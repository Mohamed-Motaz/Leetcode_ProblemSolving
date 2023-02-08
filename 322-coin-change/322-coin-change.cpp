int dp[13][10005];
int solve(int idx, int amount, vector<int> &coins)
{
    if (amount == 0)
        return 0;
    if (amount < 0)
        return 10005;
    if (idx == coins.size())
        return 10005;

    int &ans = dp[idx][amount];
    if (ans != -1)
        return ans;

    ans = 10005;
    ans = min({ans,
               solve(idx + 1, amount, coins),
               solve(idx, amount - coins[idx], coins) + 1});
    return ans;
}
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof dp);
        int ans = solve(0, amount, coins);
        ans == 10005 ? ans = -1: 0;
        return ans;
    }
};