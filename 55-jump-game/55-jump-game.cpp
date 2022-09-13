class Solution {
public:
    int dp[10004];
    vector<int> v;

    bool solve(int idx){
        if (idx == v.size() - 1)
            return true;
        if (idx >= v.size())
            return false;

        int &ans = dp[idx];
        if (ans != -1)
            return ans;

        ans = 0;

        for (int i = idx; i < v.size() && i <= idx + v[idx]; i++){
            ans += solve(i);
            if (ans)
                return ans = true;
        }
        return ans = false;
    }

    bool canJump(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        v = nums;
        return solve(0);
    }
};