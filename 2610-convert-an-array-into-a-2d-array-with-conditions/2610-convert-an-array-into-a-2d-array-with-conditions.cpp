class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int, int> mp;
        
        for (auto e: nums) mp[e]++;
        
        for (auto e: mp){
            for (int i = 0; i < e.second; i++){
                if (res.size() <= i){
                    res.push_back({});
                }
                res[i].push_back(e.first);
            }
        }
        
        return res;
    }
};