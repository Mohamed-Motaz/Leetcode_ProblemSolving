class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return 0;
        
        multiset<int> st(hand.begin(), hand.end());
        
        int ctr = 0;
        while (st.size()){
            
            int cur = *st.begin();
            st.erase(st.begin());
            int ctr = 1;
            while (ctr < groupSize){
                auto it = st.upper_bound(cur);
                if ( it != st.end() && *it == cur + 1){
                    cur++;
                    ctr++;
                    st.erase(it);
                }else{
                    return 0;
                }
            }
        }
        return st.size() == 0;
    }
};