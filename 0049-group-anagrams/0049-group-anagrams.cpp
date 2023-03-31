class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        const int n = strs.size();
        for (int i = 0; i < n; i++){
            mp[getKey(strs[i])].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto it = mp.begin(); it != mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }

    string getKey(string &s){
        vector<int> v(26, 0);
        for (char c: s) v[c - 'a']++;
        string res = "";
        for (int n: v)res += to_string(n + '0');
        return res;
    }
};