class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right(nums.size()), left(nums.size());
        right[0] = nums[0];
        left[left.size() - 1] = nums.back();

        for (int i = 1; i < nums.size(); i++)
            right[i] = right[i - 1] * nums[i];

        for (int i = nums.size() - 2; i >= 0; i--)
            left[i] = left[i + 1] * nums[i];

        vector<int> res(nums.size());
        res[0] = left[1];
        res[res.size() - 1] = right[right.size() - 2];
        for (int i = 1; i < right.size() - 1; i++)
            res[i] = right[i - 1] * left[i + 1];
        return res;
    }
};