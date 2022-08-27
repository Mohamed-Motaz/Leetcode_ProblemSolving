class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();

        multiset<int> st;
        for (int i = 0; i < k; i++ ) st.insert(nums[i]);
        res.push_back(*(prev(st.end())));

        for (int i = k; i < n; i++){
            st.erase(st.find(nums[i - k]));
            st.insert(nums[i]);
            res.push_back(*prev(st.end()));
        }
        return res;
    }
};