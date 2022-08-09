class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int e: nums) st.insert(e);

        int mx = 0;
        for (auto it = st.begin(); it != st.end(); ++it){
            int val = *it;
            //filter out the values that arent the start of the list
            if (st.find(val - 1) != st.end())
                continue;
            int ctr = 1;
            while (st.find(val + 1) != st.end()){
                val++;
                ctr++;
            }
            mx = max(ctr, mx);
        }

        return mx;
    }
};