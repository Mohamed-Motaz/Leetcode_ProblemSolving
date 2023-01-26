class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        for (auto e: s)
            v[e - 'a']++;
        for (auto e: t)
            v[e - 'a']--;
        for (auto e: v)
            if (e)
                return false;
        return true;
    }
};