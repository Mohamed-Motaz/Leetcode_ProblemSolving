class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)     {
       unordered_map<string, vector<int>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string t = strs[i];
            sort(t.begin(), t.end());
            mp[t].push_back(i);
        }
        vector<vector<string>> sol(mp.size());
        int idx = 0;
        for (pair<const string, vector<int>> &e: mp){
            for (int i: e.second){
                sol[idx].push_back(strs[i]);
            }
            ++idx;
        }

        return sol;
    }
};