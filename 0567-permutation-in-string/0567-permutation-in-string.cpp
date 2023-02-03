class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       if (s1.size() > s2.size())
        return false;

    int same = 0;
    vector<int> frq1(26), frq2(26);

    for (int i = 0; i < s1.size(); i++)
    {
        frq1[s1[i] - 'a']++;
        frq2[s2[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (frq1[i] == frq2[i])
            same++;
    }

    for (int i = s1.size(); i < s2.size(); i++)
    {
        if (same == 26)
            return true;

        int idx = s2[i] - 'a';
        frq2[idx]++;

        if (frq2[idx] == frq1[idx])
            same++;
        else if (frq1[idx] + 1 == frq2[idx])
            same--;

        idx = s2[i - s1.size()] - 'a';
        frq2[idx]--;
        if (frq2[idx] == frq1[idx])
            same++;
        else if (frq1[idx] - 1 == frq2[idx])
            same--;
    }
    return same == 26;
    }
};