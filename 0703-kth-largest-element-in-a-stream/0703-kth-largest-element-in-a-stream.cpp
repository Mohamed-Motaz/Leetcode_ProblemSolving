class KthLargest {
public:
    multiset<int> st;
    int k;
    KthLargest(int k, vector<int>& nums)
    {
        this->k = k;
        for (int e : nums)
            st.insert(e);
        while (st.size() > k)
            st.erase(st.begin());
    }

    int add(int val)
    {
        if (st.size() < k)
            st.insert(val);
        else if (val > *st.begin())
        {
            st.erase(st.begin());
            st.insert(val);
        }
        return *st.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */