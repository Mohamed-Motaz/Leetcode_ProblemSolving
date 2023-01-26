class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            auto e = mp.find(target - nums[i]);
            if (e != mp.end()){
                return {i, e->second};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};