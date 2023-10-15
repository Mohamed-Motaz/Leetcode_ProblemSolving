class Solution {
public:
    bool solveMultiSet(vector<int>& hand, int groupSize) {
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
    
    bool solveMap(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize) return 0;
        
        map<int, int> mp;
        for (int i: hand) mp[i]++;
        
        while (mp.size()){
            int cur = mp.begin()->first;
            for (int i = 0; i < groupSize; i++){
                if (mp[cur + i] <= 0) {
                    mp.erase(cur + i);
                    return 0;
                }
                
                mp[cur + i]--;
                if (mp[cur + i] <= 0) {
                    mp.erase(cur + i);
                }
            }
        }
        return 1;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        //return solveMultiSet(hand, groupSize);
        return solveMap(hand, groupSize);
    }
};