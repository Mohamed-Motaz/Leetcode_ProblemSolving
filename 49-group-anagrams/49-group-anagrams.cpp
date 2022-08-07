class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)     {
        unordered_map<string, vector<string>> mp;
        for (auto e: strs){
            string s = e;
            sort(e.begin(), e.end());
            mp[e].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto e: mp)
            res.push_back(e.second);
        return res;
    }
};