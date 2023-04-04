class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        vector<int> v;
        for (int i: nums1) s1.insert(i);
        for (int i: nums2) s2.insert(i);
        
        for (auto i: s1){
            if (s2.find(i) != s2.end())
                v.push_back(i);
        }
        return v;
    }
};