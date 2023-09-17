class Solution {
public:
    
    //iterative dp
    int i_dp(vector<int> &nums){
        vector<int> v(nums.size(), INT32_MAX);
        
        v[0] = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size() && j <= i + nums[i]; j++){
                v[j] = min(v[j], v[i] + 1);
            }
        }
        return v.back();
    }

    //recursive dp
    vector<int> dp;
    int r_dp(int cur, vector<int> &nums){
        if (cur >= nums.size() - 1)
            return 0;
        
        int &ans = dp[cur];
        if (ans != -1)
            return ans;
        
        ans = 10000;
        
        for (int i = cur + 1; i <= cur + nums[cur]; i++){
            ans = min(ans, r_dp(i, nums) + 1);
        }
        return ans;
    }
    
    //greedy
    int greedy(vector<int> &nums){
        int res = 0;
        const int n = nums.size();
        int l = 0, r = 0;
        
        while (r < n - 1){
            int far = 0;
            for (int i = l; i <= r; i++){
                far = max(far, i + nums[i]);
            }
            l = r;
            r = far;
            res++;
        }
        
        return res;
    }
    
    int jump(vector<int>& nums) {
        //return i_dp(nums);
        
        // dp.resize(nums.size(), -1);
        // return r_dp(0, nums);
        
        return greedy(nums);
    }
};