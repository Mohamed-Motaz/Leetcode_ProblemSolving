class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char, int> mp;
        for (char c : s1)
            mp[c]++;

        unordered_map<char, int> tmp = mp;
        int l = 0;
        for (int r = 0; r < s2.size(); r++)
        {
            if (mp.find(s2[r]) == mp.end())
            {
                l = r + 1;
                tmp = mp;
                continue;
            }
            tmp[s2[r]]--;
            while (l < r && tmp[s2[r]] < 0)
            {
                tmp[s2[l]]++;
                l++;
            }
            if (tmp[s2[r]] == 0)
            {
                tmp.erase(s2[r]);
            }
            if (tmp.size() == 0)
                return true;
        }

        return false;
    }
};