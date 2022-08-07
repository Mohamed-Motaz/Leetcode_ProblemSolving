class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for (auto e: nums){
            if (mp[e])
                return true;
            mp[e] = 1;
        }
        return false;
    }
};