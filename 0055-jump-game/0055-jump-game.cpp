class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx = nums[0];
        for (int i = 0; i <= mx && i < nums.size(); i++){
            mx = max(mx, nums[i] + i);
        }
        return mx >= nums.size() - 1;
    }
};