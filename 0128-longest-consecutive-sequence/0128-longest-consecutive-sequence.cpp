class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st(nums.begin(), nums.end());
        int mx = 0;
        for (auto &e : st)
        {
            // end of the sequence
            if (st.find(e - 1) == st.end())
            {
                int ctr = 1;
                int num = e + 1;
                while (st.find(num) != st.end())
                    ctr++, num++;
                mx = max(mx, ctr);
            }
        }
        return mx;
    }
};