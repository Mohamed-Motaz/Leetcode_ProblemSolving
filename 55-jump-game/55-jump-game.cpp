class Solution {
public:

    bool canJump(vector<int>& nums) {
        int mx = nums[0];

        for (int i = 0; i <= mx && i < nums.size(); i++){
            if (i == nums.size() - 1)
                return true;
            mx = max(mx, i + nums[i]);
        }

        return false;
        
    }
};