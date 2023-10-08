class Solution {
public:
    vector<vector<int>> dp;

    int solve(int left, int right, vector<int> &nums){
        if (left > right)
            return 0;
        int &ans = dp[left][right];
        if (ans != -1)
            return ans;

        for (int i = left; i <= right; i++){
            int tmp = nums[left - 1] * nums[i] * nums[right + 1];
            tmp += solve(left, i - 1, nums) + solve(i + 1, right, nums);
            ans = max(ans, tmp);    
        }
        return ans;
        
    }
    int maxCoins(vector<int>& nums) {
        dp.resize(302, vector<int>(302, -1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        return solve(1, nums.size() - 2, nums);
    }
};