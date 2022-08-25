class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26, 0);
        int l = 0, r = 0;
        int n = s.size(), mx = 0;
        int mxFreqChar = 0;
        for (; r < n; r++){
            v[s[r] - 'A']++;
            mxFreqChar = max(mxFreqChar, v[s[r] - 'A']);
            if (r - l + 1 - mxFreqChar > k)
                v[s[l] - 'A']--, l++;

            mx = max(mx, r - l + 1);
        }
        return mx;
    }
};