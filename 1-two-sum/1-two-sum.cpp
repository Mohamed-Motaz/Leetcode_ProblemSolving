class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            int needed = target - nums[i];
            if (mp[needed])
                return {mp[needed] - 1, i};
            mp[nums[i]] = i + 1;    
        }
        return {};
    }
};