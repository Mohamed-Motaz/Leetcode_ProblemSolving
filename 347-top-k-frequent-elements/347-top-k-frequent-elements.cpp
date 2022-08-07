class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int e: nums)
            mp[e]++;
        set<pair<int, int>, greater<>> st;
        for (auto e: mp)
            st.insert({e.second, e.first});

        vector<int> res;
        auto it = st.begin();
        while (k--){
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};