class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m1;
        for (char e: s) m1[e]++;
        for (char e: t) m1[e]--;
        for (auto e: m1) 
            if (e.second != 0) 
                return false;
        return true;
    }
};