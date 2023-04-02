class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int ctr = 0;
        int mx = 0;
        int l = 0;
        for (auto &c : s)
        {
            if (st.find(c) == st.end())
            {
                st.insert(c);
                ctr++;
            }
            else
            {
                while (s[l] != c)
                {
                    ctr--;
                    st.erase(s[l]);
                    l++;
                }
                // now remove the char which is like me
                l++;
            }
            mx = max(mx, ctr);
        }

        return mx;
    
    }
};