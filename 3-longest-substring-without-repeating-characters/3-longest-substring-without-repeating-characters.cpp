class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        multiset<char> st;
        int mx = 0, ctr = 0;
        int i = 0, j = 0;

        while (i < s.size() && j < s.size()){
            while (st.find(s[j]) != st.end()){
                ctr--;
                st.erase(st.find(s[i]));
                i++;
            }
            ctr++;
            st.insert(s[j]);
            j++;
            mx = max(mx, ctr);

        }
        return mx;
    }
};