class Solution {
public:
    int dp[300][5001];
    vector<int> v;
    int target;
    int solve(int idx, int curAmount)
    {
        if (idx >= v.size())
        {
            return (curAmount == target);
        }

        int &ans = dp[idx][curAmount];
        if (ans != -1)
            return ans;
        ans = 0;

        // don't take the cur val
        ans += solve(idx + 1, curAmount);

        while (curAmount + v[idx] <= target)
        {
            curAmount += v[idx];
            ans += solve(idx + 1, curAmount);
        }

        return ans;
    }

    int change(int amount, vector<int> &coins)
    {
        target = amount;
        v = coins;
        memset(dp, -1, sizeof dp);
        return solve(0, 0);
    }

};