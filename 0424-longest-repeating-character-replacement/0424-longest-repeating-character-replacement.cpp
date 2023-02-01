class Solution {
public:
    char getMostFrq(vector<int> &v)
    {
        int mx = 0, mxIdx = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] > mx)
            {
                mx = v[i];
                mxIdx = i;
            }
        }
        return mxIdx + 'A';
    }
    
    int characterReplacement(string s, int k) {
        vector<int> v(26);
        int l = 0, r = 0;
        int mx = 0;

        while (r < s.size())
        {
            v[s[r] - 'A']++;
            int len = r - l + 1;
            char mostFrq = getMostFrq(v);
            int needed = len - v[mostFrq - 'A'];
            if (needed <= k)
            {
                mx = max(mx, len);
            }
            else
            {
                v[s[l] - 'A']--;
                l++;
            }
            r++;
        }

        return mx;
    }
};