class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> sol(nums.size());

        int n = 1;
        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            sol[i] = tmp;
            tmp *= nums[i];
        }

        tmp = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (!i)
                sol[i] = tmp;
            else
                sol[i] *= tmp;
            tmp *= nums[i];
        }
        return sol;
    }
};