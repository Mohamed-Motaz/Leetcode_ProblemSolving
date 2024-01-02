class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ctr = 0;
        
        int idx = 0;
        for (auto e: s){
            if (idx >= g.size())
                break;
            
            if (e >= g[idx]){
                ctr++;
                idx++;
            }
        }
        
        return ctr;
    }
};