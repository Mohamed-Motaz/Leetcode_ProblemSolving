class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < s.size(); i++)
        {
            auto e = mp.find(s[i]);
            if (e == mp.end())
            {
                mp[s[i]] = make_pair(i, i);
            }
            else
            {
                mp[s[i]] = make_pair(e->second.first, i);
            }
        }

        vector<int> res;
        int mx = 0;
        int ctr = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i > mx)
            {
                res.push_back(ctr);
                ctr = 0;
            }
            ctr++;
            mx = max(mx, mp[s[i]].second);
        }

        if (ctr)
            res.push_back(ctr);

        return res;
        
        
    }
};