class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for (int &e: nums){
            if (st.find(e) != st.end())
                return true;
            st.insert(e);
        }
        return false;
    }
};