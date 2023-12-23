class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long tot = nums[0];
        long long mx = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] < tot)
                mx = max(mx, tot + nums[i]);
            tot += nums[i];
            
        }
        
        return mx == nums[0] ? -1 : mx;
    }
};