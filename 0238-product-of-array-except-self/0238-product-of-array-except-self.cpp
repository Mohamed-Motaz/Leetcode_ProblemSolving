class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int tmp = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res[i] = tmp, tmp *= nums[i];

        tmp = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
            res[i] *= tmp, tmp *= nums[i];

        return res;
    }
};