class Solution {
public:
    string minWindow(string s, string t)
    {
        int mnLen = INT32_MAX;
        int start = 0;

        unordered_map<char, int> curStrCtr;

        for (char c : t)
        {
            curStrCtr[c]++;
        }

        int ctr = curStrCtr.size();

        int l = 0, r = 0;
        while (r < s.size())
        {
            if (curStrCtr.find(s[r]) != curStrCtr.end()){
                curStrCtr[s[r]]--;
                if (!curStrCtr[s[r]])
                {
                    ctr--;
                }
            }
            

            while (!ctr)
            {
                if (curStrCtr.find(s[l]) != curStrCtr.end()){
                    if (r - l + 1 < mnLen)
                        mnLen = r - l + 1, start = l;

                    curStrCtr[s[l]]++;
                    if (curStrCtr[s[l]] == 1)
                    {
                        ctr++;
                    }
                }
                l++;
            }
            r++;
        }

        return mnLen == INT32_MAX ? "" : s.substr(start, mnLen);
    }
};