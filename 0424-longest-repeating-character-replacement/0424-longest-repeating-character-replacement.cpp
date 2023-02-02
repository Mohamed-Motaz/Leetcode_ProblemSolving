class Solution {
public:

    
    int characterReplacement(string s, int k) {
       vector<int> v(26);
        int l = 0, r = 0;
        int mx = 0, mxF = 0;

        while (r < s.size())
        {
            v[s[r] - 'A']++;
            int len = r - l + 1;
            mxF = max(mxF, v[s[r] - 'A']);
            int needed = len - mxF;
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