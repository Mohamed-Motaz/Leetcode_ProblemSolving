class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size()), suff(nums.size());
        pref[0] = nums[0];
        suff.back() = nums.back();

        for (int i = 1; i < nums.size() - 1; i++){
            pref[i] = pref[i - 1] * nums[i];
            suff[nums.size() - i - 1] = suff[nums.size() - i] * nums[nums.size() - i - 1];
        }

        vector<int> res(nums.size());
        res[0] =  suff[1];
        res.back() = pref[nums.size() - 2];

        for (int i = 1; i < res.size() - 1; i++){
            res[i] = pref[i - 1] * suff[i + 1];
        }
        return res;
    }
};