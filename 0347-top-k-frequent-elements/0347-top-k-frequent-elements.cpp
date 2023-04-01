class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int &i : nums)
            mp[i]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            buckets[it->second].push_back(it->first);
        }

        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; i--)
        {
            for (int j = 0; k && j < buckets[i].size(); j++)
            {
                res.push_back(buckets[i][j]);
                k--;
            }
        }
        return res;
    }
};